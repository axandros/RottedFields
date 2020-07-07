// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemAbstract.h"
#include "InventoryComponent.generated.h"

// Blueprints will bind to this to update the UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESTORYTELLER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Items that start in the inventory
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Inventory")
		TArray<class UItemAbstract*> DefaultItems;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int32 Capacity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class UItemAbstract*> Items;

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryUpdated OnInventoryUpdated;

	UFUNCTION(BlueprintCallable)
		bool AddItem(class UItemAbstract* item);

	UFUNCTION(BlueprintCallable)
		bool RemoveItem(class UItemAbstract* item);

	UFUNCTION(BlueprintCallable)
		void FirstSetup();

private:
	bool setup = false;
};
