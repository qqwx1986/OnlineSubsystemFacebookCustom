// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
 
// Module includes
#include "OnlineEventsFacebookCommon.h"
#include "OnlineSharingFacebookCommon.h"
#include "OnlineSubsystemFacebookPackage.h"

class FOnlineSubsystemFacebookCustom;
enum class EFacebookLoginResponse : uint8;

/**
 * Delegate fired when the Facebook Android SDK has completed a permissions update request
 *
 * @param InResponseCode response from the Facebook SDK
 * @param InAccessToken access token if the response was RESPONSE_OK
 */
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnFacebookRequestPermissionsOpComplete, EFacebookLoginResponse /*InResponseCode*/, const FString& /*InAccessToken*/);
typedef FOnFacebookRequestPermissionsOpComplete::FDelegate FOnFacebookRequestPermissionsOpCompleteDelegate;

/**
 * Facebook implementation of the Online Sharing Interface
 */
class FOnlineEventsFacebook : public FOnlineEventsFacebookCommon
{

public:

	virtual bool TriggerEvent( const FUniqueNetId& PlayerId, const TCHAR* EventName, const FOnlineEventParms& Parms ) override;
	virtual void SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId) override;

	/**
	 * Constructor used to indicate which OSS we are a part of
	 */
	FOnlineEventsFacebook(FOnlineSubsystemFacebookCustom* InSubsystem);
	
	/**
	 * Default destructor
	 */
	virtual ~FOnlineEventsFacebook();
};

typedef TSharedPtr<FOnlineEventsFacebook, ESPMode::ThreadSafe> FOnlineEventsFacebookPtr;