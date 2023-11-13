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
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(MyPosition);
	
	//invert movement
	if(IsGoingOutOfBoundaries())
		delta = 0.0 - delta;
	//move
	MyPosition.Y += delta * DeltaTime;
}

/**
 * 
 * @return true if the object is away from boundaries and is moving away
 * @return false otherwise 
 */
bool AMovingPlatform::IsGoingOutOfBoundaries(){
	return (delta < 0 && MyPosition.Y < MinY) || (delta > 0 && MyPosition.Y > MaxY);
}

