// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemAbstract.h"
#include "Passkey.generated.h"

/**
 * 
 */
UCLASS()
class RESTORYTELLER_API UPasskey : public UItemAbstract
{
	GENERATED_BODY()
public:
	UPasskey();

	virtual void Use(class ACharacter* Character);
};
