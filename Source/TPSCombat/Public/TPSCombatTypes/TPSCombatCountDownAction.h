// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPSCombatTypes/TPSCombatEnumTypes.h"
/**
 * 
 */
class TPSCOMBAT_API FTPSCombatCountDownAction : public FPendingLatentAction
{
public:
	FTPSCombatCountDownAction(float InTotalCountDownTime, float InUpdateInterval, float& InOutRemainingTime, ETPSCombatCountDownActionOutput& InCountDownOutput, const FLatentActionInfo& LatentInfo)
		: bNeedToCancel(false),
		  TotalCountDownTime(InTotalCountDownTime),
		  UpdateInterval(InUpdateInterval),
		  OutRemainingTime(InOutRemainingTime),
		  CountDownOutput(InCountDownOutput),
		  ExecutionFunction(LatentInfo.ExecutionFunction),
		  OutputLink(LatentInfo.Linkage),
		  CallbackTarget(LatentInfo.CallbackTarget),
		  ElapsedInterval(0.f),
		  ElapsedTimeSinceStart(0.f)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override;


	void CancelAction();

private:
	bool bNeedToCancel;
	float TotalCountDownTime;
	float UpdateInterval;
	float& OutRemainingTime;
	ETPSCombatCountDownActionOutput& CountDownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;
};
