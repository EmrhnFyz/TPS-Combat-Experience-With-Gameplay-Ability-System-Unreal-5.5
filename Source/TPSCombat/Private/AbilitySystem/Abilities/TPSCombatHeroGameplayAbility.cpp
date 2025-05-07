// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TPSCombatHeroGameplayAbility.h"
#include "Characters/TPSCombatHeroCharacter.h"
#include "Controllers/TPSCombatHeroController.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "TPSCombatGameplayTags.h"

ATPSCombatHeroCharacter* UTPSCombatHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<ATPSCombatHeroCharacter>(CurrentActorInfo->AvatarActor.Get());
	}

	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

ATPSCombatHeroController* UTPSCombatHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<ATPSCombatHeroController>(GetOwningActorFromActorInfo()->GetInstigatorController());
	}

	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : Cast<ATPSCombatHeroController>(GetOwningActorFromActorInfo()->GetInstigatorController());
}

UHeroCombatComponent* UTPSCombatHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

UHeroUIComponent* UTPSCombatHeroGameplayAbility::GetHeroUIComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroUIComponent();
}

FGameplayEffectSpecHandle UTPSCombatHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), ContextHandle);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(TPSCombatGameplayTags::Shared_SetByCaller_BaseDamage, InWeaponBaseDamage);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InUsedComboCount);
	}

	return EffectSpecHandle;
}
