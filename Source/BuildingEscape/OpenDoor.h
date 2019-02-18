// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest); //creates a class

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//returns total mass in KG
	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(BlueprintAssignable)
	FDoorRequest OnOpenRequest; //make it available in Unreal and assignable to a BP

	UPROPERTY(BlueprintAssignable)
	FDoorRequest OnCloseRequest;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	UActorComponent* ActorComponent = nullptr;

	AActor* Owner = nullptr;
};
