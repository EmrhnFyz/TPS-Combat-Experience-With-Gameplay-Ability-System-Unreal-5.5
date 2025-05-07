// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSCombatFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/TPSCombatAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"
#include "GenericTeamAgentInterface.h"
#include "TPSCombatGameplayTags.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "TPSCombatTypes/TPSCombatCountDownAction.h"

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

float UTPSCombatFunctionLibrary::GetScalableFloatValueAtLevel(const FScalableFloat& InScalableFloat, float InLevel)
{
	return InScalableFloat.GetValueAtLevel(InLevel);
}

FGameplayTag UTPSCombatFunctionLibrary::ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim, float& OutAngleDifference)
{
	check(InAttacker && InVictim);

	const FVector VictimForward = InVictim->GetActorForwardVector();
	const FVector AttackerForward = InAttacker->GetActorForwardVector();
	const FVector DirectionToAttacker = (InAttacker->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();
	const float DotResult = FVector::DotProduct(VictimForward, DirectionToAttacker);

	OutAngleDifference = UKismetMathLibrary::DegAcos(DotResult);

	const FVector CrossResult = FVector::CrossProduct(VictimForward, DirectionToAttacker);

	if (CrossResult.Z < 0.0f)
	{
		OutAngleDifference *= -1.0f;
	}

	if (OutAngleDifference >= -45.f && OutAngleDifference <= 45.f)
	{
		return TPSCombatGameplayTags::Shared_Status_HitReact_Front;
	}
	if (OutAngleDifference < -45.f && OutAngleDifference >= -135.f)
	{
		return TPSCombatGameplayTags::Shared_Status_HitReact_Left;
	}
	if (OutAngleDifference < -135.f && OutAngleDifference > 135.f)
	{
		return TPSCombatGameplayTags::Shared_Status_HitReact_Back;
	}
	if (OutAngleDifference > 45.f || OutAngleDifference <= 135.f)
	{
		return TPSCombatGameplayTags::Shared_Status_HitReact_Right;
	}

	return TPSCombatGameplayTags::Shared_Status_HitReact_Front;
}

bool UTPSCombatFunctionLibrary::IsValidBlock(AActor* InAttacker, AActor* InDefender)
{
	check(InAttacker && InDefender);

	const float DotResult = FVector::DotProduct(InAttacker->GetActorForwardVector(), InDefender->GetActorForwardVector());

	return DotResult < -0.1f;
}

bool UTPSCombatFunctionLibrary::ApplyGameplayEffectSpecHandleToTargetActor(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{
	UTPSCombatAbilitySystemComponent* SourceASC = NativeGetTPSCombatASCFromActor(InInstigator);
	UTPSCombatAbilitySystemComponent* TargetASC = NativeGetTPSCombatASCFromActor(InTargetActor);

	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = SourceASC->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data, TargetASC);

	return ActiveGameplayEffectHandle.WasSuccessfullyApplied();
}

void UTPSCombatFunctionLibrary::CountDown(const UObject* WorldContextObject, float TotalTime, float UpdateInterval, float& OutRemainingTime, ETPSCombatCountDownActionInput CountDownInput, ETPSCombatCountDownActionOutput& CountDownOutput, FLatentActionInfo LatentInfo)
{
	UWorld* World = nullptr;

	if (GEngine)
	{
		World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	}

	if (!World)
	{
		return;
	}

	FLatentActionManager& LatentActionManager = World->GetLatentActionManager();

	FTPSCombatCountDownAction* FoundAction = LatentActionManager.FindExistingAction<FTPSCombatCountDownAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

	if (CountDownInput == ETPSCombatCountDownActionInput::Start)
	{
		if (!FoundAction)
		{
			LatentActionManager.AddNewAction(
				LatentInfo.CallbackTarget,
				LatentInfo.UUID,
				new FTPSCombatCountDownAction(TotalTime, UpdateInterval, OutRemainingTime, CountDownOutput, LatentInfo)
			);
		}
	}

	if (CountDownInput == ETPSCombatCountDownActionInput::Cancel)
	{
		if (FoundAction)
		{
			FoundAction->CancelAction();
		}
	}
}
