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

