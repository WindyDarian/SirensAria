// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#pragma once

#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

UCLASS()
class SIRENSARIA_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void Move_Forward(float AxisValue); 
	void Move_Turn(float AxisValue);

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Movement")
	float speed;
	
};
