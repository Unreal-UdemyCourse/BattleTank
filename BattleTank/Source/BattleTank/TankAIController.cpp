/// Copyright Mad Science Game Studio

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ATank* PlayerTank = GetPlayerTank();
	if (!ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check acceptance radius is in cm

	AimAtPlayer();

	ATank* ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank)) { return; }
	ControlledTank->Fire();
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
	if (!ensure(PlayerTank)) { return; }

	ATank* ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank)) { return; }

	ControlledTank->AimAt(PlayerTank->GetTargetLocation()); ///If there is a targeting problem consider using GetActorLocation()
}
