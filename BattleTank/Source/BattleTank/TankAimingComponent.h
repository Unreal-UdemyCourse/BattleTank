/// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" // place new includes above this

 // Forward Declaration
class UTankBarrel;

//Holds Parameters and methods for Barrel's and Turrets
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
