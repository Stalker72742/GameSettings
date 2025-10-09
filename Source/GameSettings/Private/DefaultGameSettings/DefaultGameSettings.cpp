// Developed by Might Team


#include "DefaultGameSettings/DefaultGameSettings.h"

#include "Engine/GameEngine.h"

UDefaultGameSettings::UDefaultGameSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UDefaultGameSettings::RequestResolutionChange(int32 InResolutionX, int32 InResolutionY, EWindowMode::Type InWindowMode, bool bInDoOverrides)
{
	if (FPlatformProperties::HasFixedResolution())
	{
		return;
	}

	if (bInDoOverrides)
	{
		UGameEngine::ConditionallyOverrideSettings(InResolutionX, InResolutionY, InWindowMode);
	}

	FSystemResolution::RequestResolutionChange(InResolutionX, InResolutionY, InWindowMode);
}

void UDefaultGameSettings::ApplyResolutionSettings(bool bCheckForCommandLineOverrides)
{
#if !UE_SERVER
	QUICK_SCOPE_CYCLE_COUNTER(GameUserSettings_ApplyResolutionSettings);

	if (FPlatformProperties::HasFixedResolution())
	{
		return;
	}

	int32 NewResolutionX = ResolutionSizeX;
	int32 NewResolutionY = ResolutionSizeY;

	if (FullscreenMode == EWindowMode::WindowedFullscreen)
	{
		FDisplayMetrics DisplayMetrics;
		FDisplayMetrics::RebuildDisplayMetrics(DisplayMetrics);

		const FMonitorInfo& PrimaryMonitor = DisplayMetrics.MonitorInfo[0];

		NewResolutionX = PrimaryMonitor.NativeWidth;
		NewResolutionY = PrimaryMonitor.NativeHeight;
	}
	
	RequestResolutionChange(NewResolutionX, NewResolutionY, FullscreenMode, bCheckForCommandLineOverrides);
	
	IConsoleManager::Get().CallAllConsoleVariableSinks();
#endif
}

void UDefaultGameSettings::SetResolution(const FIntPoint& InResolution)
{
	ResolutionSizeX = InResolution.X;
	ResolutionSizeY = InResolution.Y;
}

FIntPoint UDefaultGameSettings::GetResolution() const
{
	return FIntPoint(ResolutionSizeX, ResolutionSizeY);
}