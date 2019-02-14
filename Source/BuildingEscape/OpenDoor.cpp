// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	//TODO get the chair actor
	
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
	//UE_LOG(LogTemp, Warning, TEXT("The name of this object is: %s"), *ObjectName);
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f)); //yaw, pitch, roll f means floating point

}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//TODO check for collision with chair
	 //if collision call pick up the chair

	//Poll trigger volume
	//if the actor is on the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) { //TODO OR check if chair is over the pressureplate
		
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetRealTimeSeconds();
	}

	//check if it's time to close the door
	if (GetWorld()->GetRealTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}

}

