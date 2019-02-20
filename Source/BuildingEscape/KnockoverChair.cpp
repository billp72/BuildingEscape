// Fill out your copyright notice in the Description page of Project Settings.

#include "KnockoverChair.h"
#include "GameFramework/PlayerController.h"

#define OUT
// Sets default values for this component's properties
UKnockoverChair::UKnockoverChair()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//

}

// Called when the game starts
void UKnockoverChair::BeginPlay()
{
	Super::BeginPlay();
	ThrowChair->OnActorBeginOverlap.AddUniqueDynamic(this, &UKnockoverChair::OnPressurePlate);
	ThrowChair->OnActorEndOverlap.AddUniqueDynamic(this, &UKnockoverChair::OffPressurePlate);
}

void UKnockoverChair::OffPressurePlate(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor exited: %s"), *OtherActor->GetName());
		owner->SetActorLocation(NewLocation, false, 0, ETeleportType::None);
	}
}

void UKnockoverChair::OnPressurePlate(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor entered: %s"), *OverlappedActor->GetName());
	}
}

// Called every frame
void UKnockoverChair::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}