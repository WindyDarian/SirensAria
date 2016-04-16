// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#include "SirensAria.h"
#include "CShip.h"


// Sets default values
ACShip::ACShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	//InputComponent->BindAxis("MoveForward", this, &AShip::Move_Forward);
	//InputComponent->BindAxis("Turn", this, &AShip::Move_Turn);
}

