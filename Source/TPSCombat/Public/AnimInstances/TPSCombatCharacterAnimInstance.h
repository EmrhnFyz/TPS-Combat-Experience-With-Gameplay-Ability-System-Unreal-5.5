// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/TPSCombatBaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TPSCombatCharacterAnimInstance.generated.h"

class ATPSCombatBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class TPSCOMBAT_API UTPSCombatCharacterAnimInstance : public UTPSCombatBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ATPSCombatBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration;
};
