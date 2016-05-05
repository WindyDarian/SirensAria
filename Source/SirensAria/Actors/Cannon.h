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

	UFUNCTION(BlueprintCallable, Category = "Combat")
	FVector AttackingArea(float speed, float gravity);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Combat")
	void OnFire();

	//UFUNCTION(BlueprintCallable, Category = "Combat", NetMulticast, Reliable)
	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual void Fire();

	// Horizontally rotate the cannon by an axis input
	UFUNCTION(BlueprintCallable, Category = "Cannon")
	virtual void RotateRight(float axis_input);

	// Vertically rotate the cannon by an axis input
	UFUNCTION(BlueprintCallable, Category = "Cannon")
	virtual void RotateUp(float axis_input);

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AActor> ProjectileClass;

	// Get where the rounds are fired from
	UPROPERTY(Category = "Combat", VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* ShotLocator;

	UPROPERTY(Category = "Cannon", VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* RootSceneComponent;

	UPROPERTY(Category = "Cannon", VisibleAnywhere, BlueprintReadWrite)
	float RotateSpeedH = 90;

	UPROPERTY(Category = "Cannon", VisibleAnywhere, BlueprintReadWrite)
	float RotateLimitH = 30;

	UPROPERTY(Category = "Cannon", VisibleAnywhere, BlueprintReadWrite)
	float RotateSpeedV = 90;

	UPROPERTY(Category = "Cannon", VisibleAnywhere, BlueprintReadWrite)
	float RotateLimitV = 30;
};
