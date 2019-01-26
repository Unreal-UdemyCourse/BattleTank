/// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// given a max elevation speed, and frame time

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = FMath::Clamp(RelativeRotation.Pitch + ElevationChange, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(RawNewElevation, 0.f, 0.f));
}
