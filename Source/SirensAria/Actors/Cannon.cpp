// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#include "SirensAria.h"
#include "Cannon.h"


// Sets default values
ACannon::ACannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

void ACannon::Fire()
{
	// TODO: shoot a cannonball
	UWorld* const World = GetWorld();
	if (World) {
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		auto location = GetActorLocation();
		auto rotation = GetActorRotation();
		World->SpawnActor<AActor>(ProjectileClass, location, rotation, SpawnParams);
	}

	OnFire();
}

