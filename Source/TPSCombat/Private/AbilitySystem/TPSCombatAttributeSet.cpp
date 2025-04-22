// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TPSCombatAttributeSet.h"
#include "GameplayEffectExtension.h"

#include  "TPSCombatDebugHelper.h"

UTPSCombatAttributeSet::UTPSCombatAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UTPSCombatAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);
	}
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		FString Msg = TEXT("Damage Done: ") + FString::SanitizeFloat(DamageDone) + TEXT(" Old Health") + FString::SanitizeFloat(OldHealth) + TEXT(" New Health: ") + FString::SanitizeFloat(NewCurrentHealth);
		Debug::Print(Msg);
		SetCurrentHealth(NewCurrentHealth);

		// TODO: Notify UI

		// TODO: Handle Character Death

		if (NewCurrentHealth <= 0.f)
		{
		}
	}
}
