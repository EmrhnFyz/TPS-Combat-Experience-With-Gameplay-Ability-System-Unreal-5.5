// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSCombatFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"
#include "GenericTeamAgentInterface.h"
#include "Components/Combat/PawnCombatComponent.h"

UTPSCombatAbilitySystemComponent* UTPSCombatFunctionLibrary::NativeGetTPSCombatASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UTPSCombatAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UTPSCombatFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UTPSCombatAbilitySystemComponent* ASC = NativeGetTPSCombatASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UTPSCombatFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UTPSCombatAbilitySystemComponent* ASC = NativeGetTPSCombatASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UTPSCombatFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UTPSCombatAbilitySystemComponent* ASC = NativeGetTPSCombatASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UTPSCombatFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ETPSCombatConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? ETPSCombatConfirmType::Yes : ETPSCombatConfirmType::No;
}

UPawnCombatComponent* UTPSCombatFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UTPSCombatFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, ETPSCombatValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	OutValidType = CombatComponent ? ETPSCombatValidType::Valid : ETPSCombatValidType::Invalid;

	return CombatComponent;
}

bool UTPSCombatFunctionLibrary::IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn)
{
	check(QueryPawn && TargetPawn);

	IGenericTeamAgentInterface* QueryTeamAgent = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
	IGenericTeamAgentInterface* QueryTargetTeamAgent = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());

	if (QueryTeamAgent && QueryTargetTeamAgent)
	{
		return QueryTeamAgent->GetGenericTeamId() != QueryTargetTeamAgent->GetGenericTeamId();
	}

	return false;
}
