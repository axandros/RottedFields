// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "LockableDoor.generated.h"

/**
 * 
 */
UCLASS()
class RESTORYTELLER_API ALockableDoor : public AInteractableActor
{
	GENERATED_BODY()

public:
	ALockableDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Use(class AActor* usingActor, class AController* controller = nullptr) override;

	void OpenDoor();
	void RequestOpenDoor();
	void CloseDoor();
	void RequestCloseDoor();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		bool StartsLocked = false;

	UPROPERTY(EditAnywhere)
		float DoorOpenTime = 3.0f;
	UPROPERTY(EditAnywhere)
		float DoorOpenDelay = 0.0f;
	UPROPERTY(EditAnywhere)
		float DoorCloseTime = 3.0f;
	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
		float CloseAngle = 0.0f;

	UPROPERTY(Category="Door", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* DoorMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
		class UAudioComponent *OpenSound = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
		class UAudioComponent *CloseSound = nullptr;

private:
	bool _doorIsOpen = false;
	bool _doorRequestOpen = false;
	float _doorTimer = 0.0f;
	float _doorDelayTimer = 0.0f;
	void RotateTowardsPosition(float deltaTime);
	void DoorDelay(float deltaTime);
};
