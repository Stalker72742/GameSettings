// Developed by Might Team


#include "Utils/GameSettingsHelper.h"

#include "Core/SettingsSubsystem.h"
#include "DefaultGameSettings/DefaultGameSettings.h"

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

UDefaultGameSettings* UGameSettingsHelper::GetDefaultGameSettings(UObject* WorldContextObject)
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

	if (auto subsystem = world->GetSubsystem<USettingsSubsystem>())
	{
		if (auto settings = subsystem->GetSettings())
		{
			return Cast<UDefaultGameSettings>(settings);
		}
	}

	return nullptr;
}
