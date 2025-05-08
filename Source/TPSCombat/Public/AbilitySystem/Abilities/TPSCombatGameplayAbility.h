// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include  "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "TPSCombat/Public/TPSCombatTypes/TPSCombatEnumTypes.h"
#include "TPSCombatGameplayAbility.generated.h"

class UPawnCombatComponent;
class UTPSCombatAbilitySystemComponent;

UENUM(BlueprintType)
enum class ETPSCombatAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	//~ Begin UGameplayAbility Interface.
	virtual bool DoesAbilitySatisfyTagRequirements(const UAbilitySystemComponent& AbilitySystemComponent, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category="TPSCombatAbility")
	ETPSCombatAbilityActivationPolicy AbilityActivationPolicy = ETPSCombatAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category="TPSCombat|Ability")
	UTPSCombatAbilitySystemComponent* GetTPSCombatAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyGameplayEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|Ability", meta=(DisplayName="Apply Effect Spec Handle To Target Actor", ExpandEnumAsExecs="OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyGameplayEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, ETPSCombatSuccessType& OutSuccessType);

	UFUNCTION(BlueprintCallable, Category = "TPSCombat|Ability")
	bool GetAbilityRemainingCooldownByTag(FGameplayTag InCooldownTag, float& TotalCooldownTime, float& RemainingCooldownTime);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|Ability")
	void ApplyGameplayAbilityEffectSpecHandleToHitResults(const FGameplayEffectSpecHandle& InSpecHandle, const TArray<FHitResult>& InHitResults);
};
