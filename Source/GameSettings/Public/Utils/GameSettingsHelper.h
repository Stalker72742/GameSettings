// Developed by Might Team

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameSettingsHelper.generated.h"

class UDefaultGameSettings;
class UGameSettingsObject;
/**
 * 
 */
UCLASS()
class GAMESETTINGS_API UGameSettingsHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "GameSettings", meta=(WorldContext="WorldContextObject"))
	static UGameSettingsObject* GetGameSettings(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GameSettings", meta=(WorldContext="WorldContextObject"))
	static UDefaultGameSettings* GetDefaultGameSettings(UObject* WorldContextObject);
};
