// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "REStorytellerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RESTORYTELLER_API AREStorytellerPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	void OpenInventory();

public:
	UFUNCTION(BlueprintNativeEvent)//, BlueprintCallable)
		bool DisplayString(const FString& TextToDisplay, float TimeToDisplay = 3.0f);//(FString TextToDisplay, float TimeToDisplay = 3.0f);

	virtual bool DisplayString_Implementation(const FString& TextToDisplay, float TimeToDisplay = 3.0f);
};
