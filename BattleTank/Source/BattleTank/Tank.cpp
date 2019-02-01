/// Copyright Mad Science Game Studio

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds);
	if (Barrel != nullptr && bIsReloaded)
	{
		//Spawn a projectile at the socket location on the barrel
		FVector SpawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator SpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	if (TankAimingComponent == nullptr) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
