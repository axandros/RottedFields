// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

//UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
UCLASS()
class RESTORYTELLER_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void Use(class AActor* usingActor, class AController* controller = nullptr) PURE_VIRTUAL(AInteractableActor, );

};
