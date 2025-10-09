// Developed by Might Team


#include "Core/GameSettingsObject.h"

UGameSettingsObject::UGameSettingsObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UGameSettingsObject::ApplySettings()
{
	
}

void UGameSettingsObject::ApplyResolutionSettings(bool bCheckForCommandLineOverrides)
{
	
}

void UGameSettingsObject::ApplyNonResolutionSettings(bool bCheckForCommandLineOverrides)
{
	
}

void UGameSettingsObject::SaveSettings()
{
	SaveConfig();
}

void UGameSettingsObject::SaveOnlyResolutionSettings()
{
	
}

void UGameSettingsObject::Load()
{
	LoadConfig();
}

void UGameSettingsObject::ResetToConfig()
{
	LoadConfig();
}