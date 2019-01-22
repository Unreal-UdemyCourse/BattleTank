// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtPlayer();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimAtPlayer()
{
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr) { return; }

	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr) { return; }

	ControlledTank->AimAt(PlayerTank->GetTargetLocation()); ///If there is a targeting problem consider using GetActorLocation()
}
