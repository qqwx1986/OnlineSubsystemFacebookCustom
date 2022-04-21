// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FOnlineSubsystemFacebookCustomModule : public IModuleInterface
{
public:

private:

	/** Class responsible for creating instance(s) of the subsystem */
	class FOnlineFactoryFacebook* FacebookFactory;

public:	

	// IModuleInterface 

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}
	virtual bool SupportsAutomaticShutdown() override
	{
		return false;
	}

	// FOnlineSubsystemFacebookModule

	/**
	 * Constructor
	 */
	FOnlineSubsystemFacebookCustomModule() :
		FacebookFactory(NULL)
	{}

	/**
	 * Destructor
	 */
	virtual ~FOnlineSubsystemFacebookCustomModule() 
	{}
};
