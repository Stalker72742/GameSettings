// Developed by Might Team


#include "Core/SettingsSubsystem.h"

#include "Core/DevGameSettings.h"
#include "Core/GameSettingsObject.h"

void USettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (!SettingsClass)
	{
		SettingsClass = GetDefault<UDevGameSettings>()->GameSettingsClass.LoadSynchronous();
	}

	Settings = NewObject<UGameSettingsObject>(this, SettingsClass);
	if (Settings)
	{
		Settings->Load();
	}
}

void USettingsSubsystem::Deinitialize()
{
	Super::Deinitialize();

	if (Settings)
	{
		DestroySettings();
	}
}

void USettingsSubsystem::DestroySettings()
{
	if (Settings)
	{
		Settings->ConditionalBeginDestroy();
		Settings = nullptr;
	}
}

UGameSettingsObject* USettingsSubsystem::GetSettings()
{
	if (!Settings && SettingsClass)
	{
		Settings = NewObject<UGameSettingsObject>(this, SettingsClass);
		if (Settings)
		{
			Settings->Load();
		}
	}
	return Settings;
}