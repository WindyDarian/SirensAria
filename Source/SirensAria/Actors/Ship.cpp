// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#include "SirensAria.h"
#include "Ship.h"


// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	speed = 500;
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AShip::Move_Forward);
	InputComponent->BindAxis("Turn", this, &AShip::Move_Turn);
}

void AShip::Move_Forward(float AxisValue)
{
	if (AxisValue > 0)
	{
		FVector actor_location = GetActorLocation();
		FRotator new_rotation = GetActorRotation();
		UWorld* const World = GetWorld();
		actor_location += AxisValue * speed * World->GetDeltaSeconds() * new_rotation.Vector();	 
		SetActorLocation(actor_location);
	}
}

void AShip::Move_Turn(float AxisValue)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue * 4;
	SetActorRotation(NewRotation);
}