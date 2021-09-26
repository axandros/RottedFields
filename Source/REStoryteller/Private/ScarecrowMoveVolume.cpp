// Fill out your copyright notice in the Description page of Project Settings.

#include "ScarecrowMoveVolume.h"
#include "REStorytellerCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AScarecrowMoveVolume::AScarecrowMoveVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	_trigger->AttachTo(RootComponent);

	_trigger->OnComponentBeginOverlap.AddDynamic(this, &AScarecrowMoveVolume::OnTriggerEnter);

}

void AScarecrowMoveVolume::OnTriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AREStorytellerCharacter* Character = Cast<AREStorytellerCharacter>(OtherActor);
	if (Character) {

	}
}

// Called when the game starts or when spawned
void AScarecrowMoveVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScarecrowMoveVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

