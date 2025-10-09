// Developed by Might Team


#include "Utils/GameSettingsHelper.h"

#include "Core/SettingsSubsystem.h"

UGameSettingsObject* UGameSettingsHelper::GetGameSettings(UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UWorld* world =  WorldContextObject->GetWorld();
	if (!world)
	{
		return nullptr;
	}

	return world->GetSubsystem<USettingsSubsystem>()->GetSettings();
}