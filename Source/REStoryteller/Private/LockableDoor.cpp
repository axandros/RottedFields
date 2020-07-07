// Fill out your copyright notice in the Description page of Project Settings.


#include "LockableDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

ALockableDoor::ALockableDoor() {
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorMesh->SetupAttachment(RootComponent);
	OpenSound = CreateDefaultSubobject< UAudioComponent>(TEXT("Opening Sound"));
	CloseSound = CreateDefaultSubobject< UAudioComponent>(TEXT("Closing Sound"));

}

void ALockableDoor::BeginPlay()
{
	Super::BeginPlay();

	_doorTimer = FMath::Max(DoorOpenTime, DoorCloseTime);
}

void ALockableDoor::Tick(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Lockable Door Tick"));
	Super::Tick(DeltaTime);

	RotateTowardsPosition(DeltaTime);
	DoorDelay(DeltaTime);
}

void ALockableDoor::Use(AActor * usingActor, AController * controller)
{
	if(_doorIsOpen){
		RequestCloseDoor();
	}
	else {
		RequestOpenDoor();
	}
}


void ALockableDoor::OpenDoor() {
	//UE_LOG(LogTemp, Warning, TEXT("Door is opening."));
	if (!_doorIsOpen) {
		_doorTimer = FMath::Max(DoorOpenTime - (_doorTimer / DoorCloseTime) * DoorOpenTime, 0.0f);
	}
	_doorIsOpen = true;
}


void ALockableDoor::CloseDoor() {
	if (_doorIsOpen) {
		_doorTimer = FMath::Max(DoorCloseTime - (_doorTimer / DoorOpenTime) * DoorCloseTime, 0.0f);
	}
	_doorIsOpen = false;
}

void ALockableDoor::RequestOpenDoor() {
	//UE_LOG(LogTemp, Warning, TEXT("Door has received a request to open."));
	if (!_doorRequestOpen) {
		//UE_LOG(LogTemp, Warning, TEXT("Door is processing a request to open."));
		_doorDelayTimer = 0;
		_doorRequestOpen = true;
	}
}
void ALockableDoor::RequestCloseDoor() {
	if (_doorRequestOpen) {
		_doorDelayTimer = 0;
		_doorRequestOpen = false;
	}
}

void ALockableDoor::RotateTowardsPosition(float deltaTime) {
	if (_doorIsOpen && _doorTimer < DoorOpenTime)
	{
		_doorTimer += deltaTime;
		float newYaw;
		if ( DoorMesh->GetComponentRotation().Yaw - 0.5 <= CloseAngle &&
			DoorMesh->GetComponentRotation().Yaw + 0.5 >= CloseAngle)
		{
			OpenSound->Play();
		}
		//UE_LOG(LogTemp, Warning, TEXT("Opening Door: %f | %f"), _doorTimer, _doorTimer / DoorOpenTime);
		float alpha = FMath::Clamp(_doorTimer / DoorOpenTime, 0.f, 1.f);
		newYaw = FMath::Lerp(CloseAngle, OpenAngle, alpha);

		DoorMesh->SetRelativeRotation(FRotator(0.0f, newYaw, 0.0f));
	}
	else if (!_doorIsOpen && _doorTimer < DoorCloseTime)
	{
		_doorTimer += deltaTime;
		float newYaw;

		//UE_LOG(LogTemp, Warning, TEXT("Closing Door: %f | %f"), _doorTimer, _doorTimer / DoorCloseTime);
		float alpha = FMath::Clamp(_doorTimer / DoorOpenTime, 0.f, 1.f);
		newYaw = FMath::Lerp(OpenAngle, CloseAngle, _doorTimer / DoorCloseTime);
		if (newYaw - 0.5 <= CloseAngle &&
			newYaw + 0.5 >= CloseAngle)
		{
			CloseSound->Play();
		}

		DoorMesh->SetRelativeRotation(FRotator(0.0f, newYaw, 0.0f));
	}
}

void ALockableDoor::DoorDelay(float deltaTime) {
	if (!_doorRequestOpen && _doorDelayTimer <= DoorCloseDelay) {
		if (_doorIsOpen && _doorTimer >= DoorOpenTime)
		{
			_doorDelayTimer += deltaTime;
			//UE_LOG(LogTemp, Warning, TEXT("Checking door close after delay | %f / %f"), _doorDelayTimer, DoorCloseDelay);
			if (_doorDelayTimer >= DoorCloseDelay) {
				CloseDoor();
			}
		}
		else if (DoorCloseDelay == 0) {
			CloseDoor();
		}
	}
	else if (_doorRequestOpen && _doorDelayTimer <= DoorOpenDelay) {
		if (!_doorIsOpen && _doorTimer >= DoorCloseTime) {
			_doorDelayTimer += deltaTime;
			if (_doorDelayTimer >= DoorOpenDelay) {
				OpenDoor();
			}
		}
		else if (DoorOpenDelay == 0) {
			OpenDoor();
		}
	}
}