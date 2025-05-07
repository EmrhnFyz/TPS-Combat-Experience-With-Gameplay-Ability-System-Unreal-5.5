#pragma once

UENUM()
enum class ETPSCombatConfirmType : uint8
{
	Yes,
	No,
};

UENUM()
enum class ETPSCombatValidType : uint8
{
	Valid,
	Invalid,
};

UENUM()
enum class ETPSCombatSuccessType : uint8
{
	Successful,
	Failed,
};

UENUM()
enum class ETPSCombatCountDownActionInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class ETPSCombatCountDownActionOutput : uint8
{
	Updated,
	Completed,
	Cancelled
};

UENUM(BlueprintType)
enum class ETPSCombatGameDifficulty : uint8
{
	Easy,
	Normal,
	Hard,
	VeryHard
};

UENUM(BlueprintType)
enum class ETPSCombatInputMode : uint8
{
	GameOnly,
	UIOnly
};
