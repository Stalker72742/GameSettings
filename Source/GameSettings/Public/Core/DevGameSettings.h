// Developed by Might Team

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DevGameSettings.generated.h"

class UGameSettingsObject;
/**
 * 
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Game Settings"))
class GAMESETTINGS_API UDevGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UDevGameSettings();

	UPROPERTY(Config, EditAnywhere, Category = "Settings", meta = (MustImplement = "GameSettings"))
	TSoftClassPtr<UGameSettingsObject> GameSettingsClass;

public:

	virtual FName GetCategoryName() const override;
};
