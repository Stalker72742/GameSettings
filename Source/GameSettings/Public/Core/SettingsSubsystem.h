// Developed by Might Team

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SettingsSubsystem.generated.h"

class UGameSettingsObject;
/**
 * 
 */
UCLASS()
class GAMESETTINGS_API USettingsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Destroys the settings object and releases it from memory. */
	UFUNCTION(BlueprintCallable, Category = "Settings")
	void DestroySettings();

	/** Returns the current settings object (creates it if not already created). */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Settings")
	UGameSettingsObject* GetSettings();

protected:
	/** The managed settings object. */
	UPROPERTY(Transient)
	TObjectPtr<UGameSettingsObject> Settings;

	/** Class to use for creating the settings object (can be overridden in child subsystems or via config). */
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<UGameSettingsObject> SettingsClass;

};
