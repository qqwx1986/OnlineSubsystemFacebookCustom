// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "OnlineSubsystemFacebookCommon.h"
#include "OnlineSubsystemFacebookPackage.h"

/** Forward declarations of all interface classes */
// typedef TSharedPtr<class FOnlineIdentityFacebook, ESPMode::ThreadSafe> FOnlineIdentityFacebookPtr;
// typedef TSharedPtr<class FOnlineFriendsFacebook, ESPMode::ThreadSafe> FOnlineFriendsFacebookPtr;
// typedef TSharedPtr<class FOnlineSharingFacebook, ESPMode::ThreadSafe> FOnlineSharingFacebookPtr;
// typedef TSharedPtr<class FOnlineUserFacebook, ESPMode::ThreadSafe> FOnlineUserFacebookPtr;
// typedef TSharedPtr<class FOnlineExternalUIFacebook, ESPMode::ThreadSafe> FOnlineExternalUIFacebookPtr;
// typedef TSharedPtr<class FOnlineEventsFacebook, ESPMode::ThreadSafe> FOnlineEventsFacebookPtr;

/**
 *	OnlineSubsystemFacebook - Implementation of the online subsystem for Facebook services
 */
class ONLINESUBSYSTEMFACEBOOKCUSTOM_API FOnlineSubsystemFacebookCustom
	: public FOnlineSubsystemFacebookCommon
{
public:

	// FOnlineSubsystemFacebookCommon Interface
	virtual bool Init() override;
	virtual bool Shutdown() override;
	virtual bool IsEnabled() const override;

	// FOnlineSubsystemFacebookCustom

	/**
	 * Destructor
	 */
	virtual ~FOnlineSubsystemFacebookCustom();

PACKAGE_SCOPE:

	/** Only the factory makes instances */
	FOnlineSubsystemFacebookCustom() = delete;
	explicit FOnlineSubsystemFacebookCustom(FName InInstanceName);
};

typedef TSharedPtr<FOnlineSubsystemFacebookCustom, ESPMode::ThreadSafe> FOnlineSubsystemFacebookCustomPtr;
