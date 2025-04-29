// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TPSCombatAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "TPSCombatFunctionLibrary.h"
#include "TPSCombatGameplayTags.h"
#include  "TPSCombatDebugHelper.h"
#include "Components/UI/HeroUIComponent.h"
#include "Components/UI/PawnUIComponent.h"
#include "Interfaces/PawnUIInterface.h"

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
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didnt implement PawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorLabel());

	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();
	checkf(PawnUIComponent, TEXT("PawnUIComponent is null, please check if the PawnUIComponent is assigned to the character: %s"), *Data.Target.GetAvatarActor()->GetActorLabel());

	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());

		SetCurrentRage(NewCurrentRage);
		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage() / GetMaxRage());
		}
	}
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		FString Msg = TEXT("Damage Done: ") + FString::SanitizeFloat(DamageDone) + TEXT(" Old Health") + FString::SanitizeFloat(OldHealth) + TEXT(" New Health: ") + FString::SanitizeFloat(NewCurrentHealth);
		Debug::Print(Msg);
		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		if (NewCurrentHealth <= 0.f)
		{
			UTPSCombatFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), TPSCombatGameplayTags::Shared_Status_Death);
		}
	}
}
