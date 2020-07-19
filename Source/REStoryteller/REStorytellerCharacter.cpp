// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "REStorytellerCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "InventoryComponent.h"
#include "ItemAbstract.h"
#include "REStorytellerPlayerController.h"
#include "InteractableActor.h"
#include "UObject/UObjectGlobals.h"

//////////////////////////////////////////////////////////////////////////
// AREStorytellerCharacter

AREStorytellerCharacter::AREStorytellerCharacter(const FObjectInitializer& OI) : Super(OI)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	//bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	//bUseControllerRotationRoll = false;

	GetMesh()->SetRelativeLocation(FVector(0.0, 0.0, -90.0));
	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.0, 0.0));
	   
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));

	InteractionCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("InteractionCollision"));
	InteractionCollision->SetupAttachment(RootComponent);
	InteractionCollision->SetRelativeLocation(FVector(97.0,0, 110.0));
	InteractionCollision->SetRelativeRotation(FRotator(-127,-60.0, 0.0));
	InteractionCollision->ResetRelativeTransform();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AREStorytellerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AREStorytellerCharacter::MoveForward);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &AREStorytellerCharacter::Turn);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AREStorytellerCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AREStorytellerCharacter::StopSprint);
}


void AREStorytellerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}


void AREStorytellerCharacter::Turn(float Rate)
{
	//UE_LOG(LogTemp, Warning, TEXT("Turning %f"), Rate);
	TurnAmount = Rate*TurnRate;
	AddActorLocalRotation(FRotator(0.0, TurnAmount, 0.0));
}

void AREStorytellerCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AREStorytellerCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AREStorytellerCharacter::UseItem(UItemAbstract * item)
{
	AREStorytellerPlayerController* storyController = Cast< AREStorytellerPlayerController>(GetController());
	if (storyController&& item != nullptr) {
		storyController->DisplayString(FString(item->ItemDescription.ToString()), 3.0f);
	}
}

void AREStorytellerCharacter::UseInteractable(AInteractableActor* IActor)
{
	AREStorytellerPlayerController* storyController = Cast< AREStorytellerPlayerController>(GetController());
	if (storyController&& IActor != nullptr) {
		//storyController->DisplayString(FString(IActor->GetName()), 3.0f);
		IActor->Use(this, storyController);
	}
}

/*
void AREStorytellerCharacter::BeginPlay()
{
	Inventory->FirstSetup();

	if (Controller) {
		UE_LOG(LogTemp, Warning, TEXT("Player Character possessed by %s"), *Controller->GetName());
	}
	else {
	UE_LOG(LogTemp, Warning, TEXT("Player Character is not possessed"));
	}
	
}
*/
