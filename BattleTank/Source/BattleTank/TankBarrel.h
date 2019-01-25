// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
<<<<<<< HEAD
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
=======
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = ("Collision")) /// we might need to alter the collision later
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		// Speed at which we change pitch of the barrel
>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf
		float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
<<<<<<< HEAD
		float MaxElevation = 40.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MinElevation = 0.f;

};
=======
		float MaxElevation = 20.f; 

	UPROPERTY(EditAnywhere, Category = "Setup")
		//Degrees
		float MinElevation = -5.f; //Degrees
};
>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf
