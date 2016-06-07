// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player: No Tank Controlled"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player: Possesed tank's name = %s"), *(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if(GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	// Get world location of linetrace through crosshair
	// If it hits the landscape
		// Tell the controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, 
		CrosshairYLocation * ViewportSizeY);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location =  (%s)"), *ScreenLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Screen Location =  (%d, %d)"), ViewportSizeX, ViewportSizeY);
	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)
	HitLocation = FVector(1.0);
	return true;
}
