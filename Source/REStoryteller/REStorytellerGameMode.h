// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "REStorytellerGameMode.generated.h"

UCLASS(minimalapi)
class AREStorytellerGameMode : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay();
	APlayerCameraManager* _playerCameraManager;

public:
	AREStorytellerGameMode();

	bool SetCamera(class ACameraActor camToMakeActive);

};



