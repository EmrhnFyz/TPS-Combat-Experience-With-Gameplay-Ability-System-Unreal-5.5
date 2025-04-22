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
