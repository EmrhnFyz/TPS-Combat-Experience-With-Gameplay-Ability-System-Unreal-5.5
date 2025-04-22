// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/TPSCombatHeroAnimInstance.h"

#include "Characters/TPSCombatHeroCharacter.h"

void UTPSCombatHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<ATPSCombatHeroCharacter>(OwningCharacter);
	}
}

void UTPSCombatHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = IdleElapsedTime >= EnterRelaxStateThreshold;
	}
}
