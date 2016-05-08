// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#include "SirensAria.h"
#include "Cannon.h"


// Sets default values
ACannon::ACannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<UArrowComponent>(FName(TEXT("RootSceneComponent")));
	RootComponent = RootSceneComponent;

	ShotLocator = CreateDefaultSubobject<UArrowComponent>(FName(TEXT("ShotLocation")));
	ShotLocator->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();  
}

// Called every frame
void ACannon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ACannon::RotateRight(float axis_input)
{
	UWorld* World = GetWorld();
	if (World)
	{
		auto delta_t = World->DeltaTimeSeconds;
		auto rot = RootComponent->GetRelativeTransform().Rotator();;
		
		rot.Yaw = FMath::ClampAngle(rot.Yaw + RotateSpeedH * axis_input * delta_t, -RotateLimitH, RotateLimitH);
		RootComponent->SetRelativeRotation(rot.Quaternion());
	}
}

void ACannon::RotateUp(float axis_input)
{
	UWorld* World = GetWorld();
	if (World)
	{
		auto delta_t = World->DeltaTimeSeconds;
		auto rot = RootComponent->GetRelativeTransform().Rotator();;
		rot.Pitch = FMath::ClampAngle(rot.Pitch + RotateSpeedV * axis_input * delta_t, -RotateLimitV , RotateLimitV);
		RootComponent->SetRelativeRotation(rot.Quaternion());
	}
}

void ACannon::PitchTo(float pitch, float speed_factor)
{
	UWorld* World = GetWorld();
	if (World)
	{
		auto delta_t = World->DeltaTimeSeconds;
		auto rot = RootComponent->GetRelativeTransform().Rotator();;
		rot.Pitch = FMath::ClampAngle((pitch - rot.Pitch) * speed_factor * delta_t + rot.Pitch, -RotateLimitV, RotateLimitV);
		RootComponent->SetRelativeRotation(rot.Quaternion());
	}
}

//void ACannon::Fire_Implementation()
//{
//	UWorld* const World = GetWorld();
//	if (World) 
//	{
//		FActorSpawnParameters SpawnParams;
//		SpawnParams.Owner = this;
//		SpawnParams.Instigator = Instigator;
//		//auto location = GetActorLocation();
//		auto location = ShotLocator->GetComponentLocation();
//		auto rotation = GetActorRotation();
//		World->SpawnActor<AActor>(ProjectileClass, location, rotation, SpawnParams);
//	}
//
//	OnFire();
//}

void ACannon::Fire()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		//auto location = GetActorLocation();
		auto location = ShotLocator->GetComponentLocation();
		auto rotation = GetActorRotation();
		World->SpawnActor<AActor>(ProjectileClass, location, rotation, SpawnParams);
	}

	OnFire();
}


FVector ACannon::AttackingArea(float speed, float gravity)
{
	FVector result;
	float temp = gravity / speed / speed;
	auto shot_trans = ShotLocator->GetComponentTransform();
	auto pos = shot_trans.GetLocation();
	auto forward = shot_trans.GetRotation().GetForwardVector();
	FVector forwardInXYPlain = FVector(forward.X,forward.Y,0);
	forwardInXYPlain=(forwardInXYPlain.SafeNormal());
	//theta and tan(theta) in 2D
	float theta = forward.Z / sqrt(pow(forward.X, 2) + pow(forward.Y, 2));
	float tan = FMath::Tan(theta);
	//distance from cannon to attacking area in 2D;
	float temp2 = temp + temp*pow(tan, 2);
	float distance = (-tan + sqrt(pow(tan, 2) - 2 * (-pos.Z) * temp2 )) / (-temp2);

	result = FVector(forwardInXYPlain.X*distance+ pos.X, forwardInXYPlain.Y*distance+pos.Y,-pos.Z);
	return result;
}