// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#pragma once

#include "GameFramework/Actor.h"
#include "Cannon.generated.h"

UCLASS()
class SIRENSARIA_API ACannon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat")
	void OnFire();
	
    virtual void Fire();


};
