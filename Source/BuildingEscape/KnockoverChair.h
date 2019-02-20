// Fill out your copyright notice in the Description page of Project Settings.*

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "KnockoverChair.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UKnockoverChair : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKnockoverChair();

	//Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OffPressurePlate(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnPressurePlate(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* ThrowChair = nullptr;

	UPROPERTY(EditAnywhere, Category = "Location")
	FVector NewLocation = FVector(0.f, -20.f, 0);

	AActor* owner = GetOwner();

};
