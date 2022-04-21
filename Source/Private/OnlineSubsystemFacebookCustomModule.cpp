// Copyright Epic Games, Inc. All Rights Reserved.

#include "OnlineSubsystemFacebookCustomModule.h"

#include "OnlineSubsystem.h"
#include "OnlineSubsystemFacebookPrivate.h"

#define LOCTEXT_NAMESPACE "FOnlineSubsystemFacebookCustomModule"


/**
 * Class responsible for creating instance(s) of the subsystem
 */
class FOnlineFactoryFacebook : public IOnlineFactory
{
public:

	FOnlineFactoryFacebook() {}
	virtual ~FOnlineFactoryFacebook() {}

	virtual IOnlineSubsystemPtr CreateSubsystem(FName InstanceName)
	{
		FOnlineSubsystemFacebookCustomPtr OnlineSub = MakeShared<FOnlineSubsystemFacebookCustom, ESPMode::ThreadSafe>(InstanceName);
		if (OnlineSub->IsEnabled())
		{
			UE_LOG_ONLINE(Log, TEXT("Facebook API is being initialized."));

			if(!OnlineSub->Init())
			{
				UE_LOG_ONLINE(Warning, TEXT("Facebook API failed to initialize!"));
				OnlineSub->Shutdown();
				OnlineSub.Reset();
			}
		}
		else
		{
			UE_LOG_ONLINE(Warning, TEXT("Facebook API disabled!"));
			OnlineSub->Shutdown();
			OnlineSub.Reset();
		}

		return OnlineSub;
	}
};

void FOnlineSubsystemFacebookCustomModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG_ONLINE(Log, TEXT("Facebook Module Startup!"));

	FacebookFactory = new FOnlineFactoryFacebook();

	// Create and register our singleton factory with the main online subsystem for easy access
	FOnlineSubsystemModule& OSS = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OSS.RegisterPlatformService(FACEBOOK_SUBSYSTEM, FacebookFactory);
}

void FOnlineSubsystemFacebookCustomModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UE_LOG_ONLINE(Log, TEXT("Facebook Module Shutdown!"));

	FOnlineSubsystemModule& OSS = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OSS.UnregisterPlatformService(FACEBOOK_SUBSYSTEM);

	delete FacebookFactory;
	FacebookFactory = NULL;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOnlineSubsystemFacebookCustomModule, OnlineSubsystemFacebookCustom)