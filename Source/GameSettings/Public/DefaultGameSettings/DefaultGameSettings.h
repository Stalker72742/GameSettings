// Developed by Might Team

#pragma once

#include "CoreMinimal.h"
#include "Core/GameSettingsObject.h"
#include "DefaultGameSettings.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Config=GameSettings)
class GAMESETTINGS_API UDefaultGameSettings : public UGameSettingsObject
{
	GENERATED_BODY()
public:
	UDefaultGameSettings(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(Config)
	float FrameRateLimit {60};

	UPROPERTY(Config)
	bool bUseUnlimitFPS {false};

	UPROPERTY(Config)
	bool bUseVSync {false};

	UPROPERTY(Config)
	TEnumAsByte<EWindowMode::Type> FullscreenMode;

	UPROPERTY(Config)
	int32 ResolutionSizeX;

	UPROPERTY(Config)
	int32 ResolutionSizeY;

protected:

	virtual void RequestResolutionChange(int32 InResolutionX, int32 InResolutionY, EWindowMode::Type InWindowMode, bool bInDoOverrides = true);

public:

	virtual void ApplyResolutionSettings(bool bCheckForCommandLineOverrides) override;

public:

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetFullscreenMode(const TEnumAsByte<EWindowMode::Type>& InFullscreenMode) { FullscreenMode = InFullscreenMode; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	TEnumAsByte<EWindowMode::Type> GetFullscreenMode() const { return FullscreenMode; }

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetResolution(const FIntPoint& InResolution);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FIntPoint GetResolution() const;
};
