// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Capacity = 4;
	DefaultItems = TArray<UItemAbstract*>();

	// ...
}

void UInventoryComponent::FirstSetup()
{
	UE_LOG(LogTemp, Warning, TEXT("Running Invenotry First Setup"));
	if(!setup){
		setup = true;
		UE_LOG(LogTemp, Warning, TEXT("Capacity: %i Default Items Num: %i"), Capacity, DefaultItems.Num());
		for (auto& Item : DefaultItems) {
			AddItem(Item);
		}
	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{ Super::BeginPlay(); UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));}

bool UInventoryComponent::AddItem(UItemAbstract * item)
{
	UE_LOG(LogTemp, Warning, TEXT("Entered AddItem"));
	if (item != nullptr && Items.Num() < Capacity){
		UE_LOG(LogTemp, Warning, TEXT("Adding Item %s"), *item->ItemDislpayName.ToString());
		Items.Add(item);
		item->OwningInventory = this;
		item->World = GetWorld();
	}
	return false;
}

bool UInventoryComponent::RemoveItem(UItemAbstract * item)
{
	bool ret = false;
	if (Items.Contains(item)) {
		Items.Remove(item);

	}
	return ret;
}