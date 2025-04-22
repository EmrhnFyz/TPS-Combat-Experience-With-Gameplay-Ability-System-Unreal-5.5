// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "AttributeSet.h"
#include "TPSCombatAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UTPSCombatAttributeSet();
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, CurrentHealth);

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category="Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, CurrentRage);

	UPROPERTY(BlueprintReadOnly, Category="Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, MaxRage);

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, AttackPower);

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, DamageTaken);

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UTPSCombatAttributeSet, DefensePower);
};
