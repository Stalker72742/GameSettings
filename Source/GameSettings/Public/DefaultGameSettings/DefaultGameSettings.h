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
	TEnumAsByte<EWindowMode::Type> FullscreenMode {EWindowMode::Type::Fullscreen};

	UPROPERTY(Config)
	uint32 ResolutionSizeX;

	UPROPERTY(Config)
	uint32 ResolutionSizeY;

	UPROPERTY(Config)
	int32 AntiAliasingQuality {1};

	UPROPERTY(Config)
	int32 FoliageQuality {1};

	UPROPERTY(Config)
	int32 GlobalIlluminationQuality {1};

	UPROPERTY(Config)
	int32 PostProcessingQuality {1};

	UPROPERTY(Config)
	int32 ReflectionQuality {1};

	UPROPERTY(Config)
	int32 ShadingQuality {1};

	UPROPERTY(Config)
	int32 ShadowQuality {1};

	UPROPERTY(Config)
	int32 TextureQuality {1};

	UPROPERTY(Config)
	int32 ViewDistanceQuality {1};

	UPROPERTY(Config)
	int32 VisualEffectsQuality {1};

	UPROPERTY(Config)
	int32 OverallScalabilityQuality {1};

protected:

	virtual void RequestResolutionChange(int32 InResolutionX, int32 InResolutionY, EWindowMode::Type InWindowMode, bool bInDoOverrides = true);

public:

	virtual void ApplyResolutionSettings(bool bCheckForCommandLineOverrides) override;

public:
	
	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetFullscreenMode(const TEnumAsByte<EWindowMode::Type>& InFullscreenMode) { FullscreenMode = InFullscreenMode; }

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetResolution(const FIntPoint& InResolution);
	
	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetAntiAliasing(int32 InAntiAliasing);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetFoliageQuality(int32 InFoliageQuality);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetGlobalIlluminationQuality(int32 InGlobalIllumination);
	
	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetPostProcessingQuality(int32 InPostProcessing);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetReflectionQuality(int32 InReflectionQuality);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetShadingQuality(int32 InShadingQuality);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetShadowQuality(int32 InShadowQuality);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetTextureQuality(int32 InTextureQuality);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetViewDistanceQuality(int32 InViewDistance);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetVisualEffectsQuality(int32 InVisualEffects);

	UFUNCTION(BlueprintCallable, Category = "Default game Settings")
	void SetOverallScalabilityQuality(int32 InOverallScalability);

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetAntiAliasing() const { return AntiAliasingQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetFoliageQuality() const { return FoliageQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetGlobalIlluminationQuality() const { return GlobalIlluminationQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetPostProcessingQuality() const { return PostProcessingQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetReflectionQuality() const { return ReflectionQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetShadingQuality() const { return ShadingQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetShadowQuality() const { return ShadowQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetTextureQuality() const { return TextureQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetViewDistanceQuality() const { return ViewDistanceQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetVisualEffectsQuality() const { return VisualEffectsQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FORCEINLINE int32 GetOverallScalabilityQuality() const { return OverallScalabilityQuality; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	FIntPoint GetResolution() const { return FIntPoint(ResolutionSizeX, ResolutionSizeY); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Default game Settings")
	TEnumAsByte<EWindowMode::Type> GetFullscreenMode() const { return FullscreenMode; }
};
