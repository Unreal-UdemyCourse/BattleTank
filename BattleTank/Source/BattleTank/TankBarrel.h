// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories("Collision")) // may need to edit collision at some point
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MaxElevation = 40.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MinElevation = 0.f;

};