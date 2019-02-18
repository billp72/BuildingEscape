// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

#define OUT //TODO make out work across the project scope
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate) { 
		UE_LOG(LogTemp, Warning, TEXT("Presure plate missing triggerVolume from: %s"), *Owner->GetName());
	}
	//TODO get the chair actor
	
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll trigger volume
	//if the actor is on the volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass) { //TODO need to make float a parameter for editing in game engine
		
		OnOpenRequest.Broadcast();

	}
	else {
		//TODO put close do code here
		OnCloseRequest.Broadcast();
	}

}

float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors; //out parameter - array of actor pointers
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	//find overlapping actors
	for (const auto& Actor : OverlappingActors) 
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

		UE_LOG(LogTemp, Warning, TEXT("Mass of: %s"), *Actor->GetName());

	}
	//iterate through them adding their total mass

	return TotalMass;
}