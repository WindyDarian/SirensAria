// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#include "SirensAria.h"
#include "ShipWheel.h"


// Sets default values
AShipWheel::AShipWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShipWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipWheel::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

