// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = ("Collision")) /// we might need to alter the collision later
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		// Speed at which we change pitch of the barrel
		float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MaxElevation = 20.f; 

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MinElevation = -5.f; //Degrees
};
