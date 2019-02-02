/// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h" // place new includes above this


//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward Declarations
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

//Holds Parameters and methods for Barrel's and Turrets
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	// TODO add SetTurretReference

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus AimingState = EFiringStatus::Aiming;

private:	

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
		
	void MoveBarrelTowards(FVector AimDirection);
};
