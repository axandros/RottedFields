// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScarecrowMoveVolume.generated.h"

UCLASS()
class RESTORYTELLER_API AScarecrowMoveVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScarecrowMoveVolume();

	void OnTriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
		bool _isActive;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category="Scarecrow Volume")
		class UBoxComponent* _trigger;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
