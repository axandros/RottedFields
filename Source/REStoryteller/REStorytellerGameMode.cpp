// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "REStorytellerGameMode.h"
#include "REStorytellerCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Camera/PlayerCameraManager.h"

void AREStorytellerGameMode::BeginPlay()
{
	Super::BeginPlay();

	_playerCameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	if (_playerCameraManager == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Player Camera Manager not found!"));
	}
}

AREStorytellerGameMode::AREStorytellerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

bool AREStorytellerGameMode::SetCamera(ACameraActor camToMakeActive)
{
	bool ret = false;
	if (_playerCameraManager) {
		
		//_playerCameraManager->SetCam

		ret = true;
	}
	return ret;
}
