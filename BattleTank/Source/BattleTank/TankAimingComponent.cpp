// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
<<<<<<< HEAD
=======

>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (Barrel == nullptr) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	AActor* OwningActor = GetOwner();
	TArray<AActor*> ActorsToIgnore = TArray<AActor*>();

	if (OwningActor != nullptr)
	{
		ActorsToIgnore.Add(OwningActor);
	}


	// Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::OnlyTraceWhileAscending,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor *>(ActorsToIgnore),
		true
	);

	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
<<<<<<< HEAD
	
	Barrel->Elevate(5); // TODO remove magic Number
=======

	Barrel->Elevate(5); // TODO remove magic number
>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf
}