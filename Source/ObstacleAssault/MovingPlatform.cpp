// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("Configured distance: %f"),MaxDistance);
	UE_LOG(LogTemp, Display, TEXT("Configured velocity: %f"),PlatformVelocity);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	//update position
	UpdatePosition(DeltaTime);

	//Boundary reached
	if(ShouldRevertMovementDirection())
	{
		float OverShoot = CapLocationAndReverseVelocity();
		UE_LOG(LogTemp, Warning, TEXT("%s Pltform overshot: %f"),*GetName(), OverShoot);


		
	}

}

void AMovingPlatform::UpdatePosition(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
}

/**
 * @brief cap the location to max distance and reverse the velocity
 * 
 * @return float overshot of the cap 
 */
float AMovingPlatform::CapLocationAndReverseVelocity()
{
		//Evaluate the distance to avoid shifting
		//Cap the EndingLocationCapped with the max distance from the StartLocation
		//	this way, when the distance is overshoot by the previous CurrentPosition evaluation
		//  it is capped at the max distance that the object can reach
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector EndingLocationCapped = StartLocation + (MoveDirection * MaxDistance);
		
		//Assign the new StartLocation with the EndingLocationCapped
		StartLocation = EndingLocationCapped;

		//Update the position of the actor with the capped location
		SetActorLocation(StartLocation);


		//Reverse direction
		PlatformVelocity = - PlatformVelocity;
		return MovedDistance - MaxDistance;
}

bool AMovingPlatform::ShouldRevertMovementDirection() const
{
	return GetDistanceMoved() > MaxDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return  FVector::Distance(StartLocation, GetActorLocation());
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	
	AddActorLocalRotation(PlatformAngularVelocity * DeltaTime);

}