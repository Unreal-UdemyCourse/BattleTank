/// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


<<<<<<< HEAD
void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond)
}
=======


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amount this frame
	// given a max elevation speed, and frame time
	UE_LOG(LogTemp, Warning, TEXT("Elevate(%f) called"), DegreesPerSecond)
}
>>>>>>> 155878451d76233b31a32416a84c94fc7ac65caf
