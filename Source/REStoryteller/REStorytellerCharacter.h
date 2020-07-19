// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "REStorytellerCharacter.generated.h"

UCLASS(config=Game)
class AREStorytellerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AREStorytellerCharacter(const class FObjectInitializer& OI);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;
	
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//virtual void BeginPlay() override;
	// End of APawn interface

	UPROPERTY(VisibleAnywhere, BLueprintReadOnly, Category = "Inventory")
		class UInventoryComponent* Inventory;

	UPROPERTY(VisibleAnywhere, BLueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Interactions")
		class UCapsuleComponent* InteractionCollision;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
		void Turn(float Rate);

	void StartSprint();
	void StopSprint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement")
		float TurnAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement")
		float TurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement")
		float WalkSpeed = 125.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement")
		float SprintSpeed = 125.0f;

	UFUNCTION(BlueprintCallable)
		void UseItem(class UItemAbstract* item);

	UFUNCTION(BlueprintCallable)
		void UseInteractable(class AInteractableActor* IActor);
};

