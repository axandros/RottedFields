// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemAbstract.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RESTORYTELLER_API UItemAbstract : public UObject
{
	GENERATED_BODY()

public:
	UItemAbstract();

	UPROPERTY(Transient)
		class UWorld* World;

	virtual class UWorld* GetWorld() const { return World; };

	// The text for using the item. - EG, the item tooltip
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText UseActionText;

	// The mesh to display for this items pickup
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* PickupMesh;

	// The Thumbnail for this item.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnail;

	// Display name for the item in the inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDislpayName;

	// An optional description for the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (Multiline = true))
		FText ItemDescription;

	// Weight of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float Weight;

	// The inventory that owns this item.
	UPROPERTY()
		class UInventoryComponent* OwningInventory;

	virtual void Use(class ACharacter* Character) PURE_VIRTUAL(UItemAbstract, );

};
