/// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/CollisionQueryParams.h"
#include "TankPlayerController.generated.h" // must be the last include


//Forward declarations
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected:
	// No Implematation in cpp for a BlueprintImplimentableEvent
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

	UTankAimingComponent* AimingComponent = nullptr;

private:
	// # TODO ask the player UI widget for this
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 1.f / 3.f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f; // 10km

	//Move the barrel so the shot will hit where crosshair intersects with the world
	void AimTowardsCrosshair();

	// Return an out parameter, return true if hit terrain or an enemy
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
