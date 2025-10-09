// Developed by Might Team


#include "Core/DevGameSettings.h"

#include "Core/GameSettingsObject.h"

UDevGameSettings::UDevGameSettings()
{
	GameSettingsClass = UGameSettingsObject::StaticClass();
}

FName UDevGameSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}