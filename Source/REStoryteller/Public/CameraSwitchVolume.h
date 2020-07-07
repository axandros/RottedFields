// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraSwitchVolume.generated.h"

//Forward Declaration
class UBoxComponent;
class UTextRenderComponent;
class AFixedCamera;

UCLASS()
class RESTORYTELLER_API ACameraSwitchVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraSwitchVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Components
	UBoxComponent* BoxCollision;

	UTextRenderComponent* TextRenderNewCamera;
	UTextRenderComponent* TextRenderPreviousCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Construction Script
	virtual void OnConstruction(const FTransform& Transform);

protected:
	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Volume")
		float VolumeWidth = 32.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Volume")
		float VolumeHeight = 32.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
		AFixedCamera* NewCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
		AFixedCamera* PreviousCamera;

	// Overlap Event
	UFUNCTION()
		void OnEndOverlap(class AActor* ThisActor, class AActor* OtherActor);
};
