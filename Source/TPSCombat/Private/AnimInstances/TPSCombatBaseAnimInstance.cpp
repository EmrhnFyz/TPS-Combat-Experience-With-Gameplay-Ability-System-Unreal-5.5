// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/TPSCombatBaseAnimInstance.h"
#include "TPSCombatFunctionLibrary.h"

bool UTPSCombatBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UTPSCombatFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}

	return false;
}
