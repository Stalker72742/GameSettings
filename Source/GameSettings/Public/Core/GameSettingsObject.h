// Developed by Might Team

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameSettingsObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Config=GameSettings)
class GAMESETTINGS_API UGameSettingsObject : public UObject
{
	GENERATED_BODY()

public:
	UGameSettingsObject(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void ApplySettings();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void ApplyResolutionSettings(bool bCheckForCommandLineOverrides);

	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void ApplyNonResolutionSettings(bool bCheckForCommandLineOverrides);
	
	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void SaveSettings();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void SaveOnlyResolutionSettings();	
	
	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void Load();
	
	UFUNCTION(BlueprintCallable, Category = "Settings")
	virtual void ResetToConfig();
};

