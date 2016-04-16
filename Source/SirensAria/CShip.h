// Copyright (C) 2016  Ruoyu Fan, Xueyin Wan, Menglu Wang

#pragma once

#include "GameFramework/Pawn.h"
#include "CShip.generated.h"

UCLASS()
class SIRENSARIA_API ACShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	//void Move_Forward(float AxisValue); 
	//void Move_Turn(float AxisValue);

};
