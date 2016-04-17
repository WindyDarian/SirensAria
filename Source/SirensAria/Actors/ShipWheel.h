// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#pragma once

#include "GameFramework/Actor.h"
#include "ShipWheel.generated.h"

UCLASS()
class SIRENSARIA_API AShipWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShipWheel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
