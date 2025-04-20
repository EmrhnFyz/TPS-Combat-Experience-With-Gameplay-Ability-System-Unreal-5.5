// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "TPSCombatInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Callback);
};

template <class UserObject, typename CallbackFunc>
void UTPSCombatInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                     const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent,
                                                     UserObject* ContextObject, CallbackFunc Callback)
{
	checkf(InInputConfig,
	       TEXT("Input Config data asset is null, please check the input config data asset in the input component!"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Callback);
	}
}
