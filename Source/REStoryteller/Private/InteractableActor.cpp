// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AInteractableActor::Tick(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Interactable Actor Tick"));
	Super::Tick(DeltaTime);
}
