// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" // place new includes above this

 // Forward Declaration
class UTankBarrel;

<<<<<<< HEAD
class UTankBarrel; // Forward Declaration

=======
//Holds Parameters and methods for Barrel's and Turrets
>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	// TODO add SetTurretReference

protected:

private:	

	UTankBarrel* Barrel = nullptr;
		
	void MoveBarrelTowards(FVector AimDirection);
};
