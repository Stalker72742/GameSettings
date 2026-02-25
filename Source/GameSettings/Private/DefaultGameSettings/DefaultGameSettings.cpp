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

void UDefaultGameSettings::SetAntiAliasing(int32 InAntiAliasing)
{
	AntiAliasingQuality = InAntiAliasing;
}

void UDefaultGameSettings::SetFoliageQuality(int32 InFoliageQuality)
{
	FoliageQuality = InFoliageQuality;
}

void UDefaultGameSettings::SetGlobalIlluminationQuality(int32 InGlobalIllumination)
{
	GlobalIlluminationQuality = InGlobalIllumination;
}

void UDefaultGameSettings::SetPostProcessingQuality(int32 InPostProcessing)
{
	PostProcessingQuality = InPostProcessing;
}

void UDefaultGameSettings::SetReflectionQuality(int32 InReflectionQuality)
{
	ReflectionQuality = InReflectionQuality;
}

void UDefaultGameSettings::SetShadingQuality(int32 InShadingQuality)
{
	ShadingQuality = InShadingQuality;
}

void UDefaultGameSettings::SetShadowQuality(int32 InShadowQuality)
{
	ShadowQuality = InShadowQuality;
}

void UDefaultGameSettings::SetTextureQuality(int32 InTextureQuality)
{
	TextureQuality = InTextureQuality;
}

void UDefaultGameSettings::SetViewDistanceQuality(int32 InViewDistance)
{
	ViewDistanceQuality = InViewDistance;
}

void UDefaultGameSettings::SetVisualEffectsQuality(int32 InVisualEffects)
{
	VisualEffectsQuality = InVisualEffects;
}

void UDefaultGameSettings::SetOverallScalabilityQuality(int32 InOverallScalability)
{
	OverallScalabilityQuality = InOverallScalability;
}
