// Fill out your copyright notice in the Description page of Project Settings.


#include "REStorytellerPlayerController.h"

void AREStorytellerPlayerController::BeginPlay() {
	//GetCharacter()->PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AREStorytellerPlayerController::OpenInventory);
}

void AREStorytellerPlayerController::OpenInventory()
{
}


bool AREStorytellerPlayerController::DisplayString_Implementation(const FString& TextToDisplay, float TimeToDisplay)//(FString TextToDisplay, float TimeToDisplay)
{
	return false;
}