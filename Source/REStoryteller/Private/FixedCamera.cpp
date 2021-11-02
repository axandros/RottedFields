// Fill out your copyright notice in the Description page of Project Settings.
#include "FixedCamera.h"
#include "Kismet//GameplayStatics.h"
#include "Camera/CameraComponent.h"

AFixedCamera::AFixedCamera()
{
	StartingCamera = false;
	GetCameraComponent()->SetAspectRatio(2.35);
	GetCameraComponent()->SetFieldOfView(75.0f);
}

void AFixedCamera::BeginPlay()
{

	if (StartingCamera) {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(/*(GetWorld()*/ this, 0);

		if (PlayerController)
		{
			//FViewTargetTransitionParams TransitionParams;
			//PlayerController->SetViewTarget(this, TransitionParams);
		}
	}
	
}
