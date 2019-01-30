/// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	 return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr) { return; }

	FVector HitLocation; // OUT PARAMETER
	if (GetSightRayHitLocation(HitLocation))
	{
		ControlledTank->AimAt(HitLocation);
	}
}

// get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Get the pixel Location of the crosshair
	int32 ViewportSizeX, ViewPortSizeY;
	GetViewportSize(ViewportSizeX, ViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);

	FVector LookDirection;
	FVector HitLocation;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// line trace from end of barrel to the crosshair coordinates * distance.
		// if we hit something
		if (GetLookVectorHitLocation(LookDirection, HitLocation))
		{
			// write the hit result's location vector to HitLocation
			OutHitLocation = HitLocation;
			return true;
		}
		else { return false; }
	}

	else { return false; }

}

// convert pixel location to a normal vector in world coordinates
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // we don't need this
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	UWorld* World = GetWorld();
	if(World == nullptr) { return false; }

	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	bool bHit = World->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	);

	if (bHit)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		HitLocation = FVector(0.f);
		return false;
	}
}
