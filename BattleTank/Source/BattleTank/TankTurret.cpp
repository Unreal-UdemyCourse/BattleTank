// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"




void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewYawRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.f, RawNewYawRotation, 0.f));

	float TimeSeconds = GetWorld()->TimeSeconds;
}
