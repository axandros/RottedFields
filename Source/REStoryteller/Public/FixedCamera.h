// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FixedCamera.generated.h"

/**
 * 
 */
UCLASS()
class RESTORYTELLER_API AFixedCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:
	// Constructor
	AFixedCamera();

	// Begin Play
	virtual void BeginPlay() override;

protected:
	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
		bool StartingCamera;
};
