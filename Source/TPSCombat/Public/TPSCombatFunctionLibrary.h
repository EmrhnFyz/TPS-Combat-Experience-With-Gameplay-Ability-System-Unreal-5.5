// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TpsCombatTypes/TPSCombatEnumTypes.h"
#include "TPSCombatFunctionLibrary.generated.h"

class UPawnCombatComponent;
class UTPSCombatAbilitySystemComponent;
struct FGameplayTag;
struct FScalableFloat;

/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UTPSCombatAbilitySystemComponent* NativeGetTPSCombatASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|FunctionLibrary", meta=(DisplayName="Does Actor Have Tag", ExpandEnumAsExecs="OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ETPSCombatConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|FunctionLibrary", meta=(DisplayName="Get Pawn Combat Component From Actor", ExpandEnumAsExecs="OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, ETPSCombatValidType& OutValidType);

	UFUNCTION(BlueprintPure, Category="TPSCombat|FunctionLibrary")
	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);

	UFUNCTION(BlueprintPure, Category="TPSCombat|FunctionLibrary", meta=(CompactNodeTitle = "GetValueAtLevel"))
	static float GetScalableFloatValueAtLevel(const FScalableFloat& InScalableFloat, float InLevel = 1.0);

	UFUNCTION(BlueprintPure, Category="TPSCombat|FunctionLibrary")
	static FGameplayTag ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim, float& OutAngleDifference);

	UFUNCTION(BlueprintPure, Category="TPSCombat|FunctionLibrary")
	static bool IsValidBlock(AActor* InAttacker, AActor* InDefender);

	UFUNCTION(BlueprintCallable, Category="TPSCombat|FunctionLibrary")
	static bool ApplyGameplayEffectSpecHandleToTargetActor(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "TPSCombat|FunctionLibrary", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", ExpandEnumAsExecs = "CountDownInput|CountDownOutput", TotalTime = "1.0", UpdateInterval = "0.1"))
	static void CountDown(const UObject* WorldContextObject, float TotalTime, float UpdateInterval,
	                      float& OutRemainingTime, ETPSCombatCountDownActionInput CountDownInput,
	                      UPARAM(DisplayName = "Output")
	                      ETPSCombatCountDownActionOutput& CountDownOutput, FLatentActionInfo LatentInfo);
};
