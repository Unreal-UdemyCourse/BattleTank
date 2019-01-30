// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"




void UTankMovementComponent::IntendMoveForward(float Throw)
{
	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f Throttle at %f"), Time, Throw)
}
