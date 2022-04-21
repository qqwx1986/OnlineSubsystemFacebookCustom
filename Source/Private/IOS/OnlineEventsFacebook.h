// Copyright Epic Games, Inc. All Rights Reserved.


#pragma once
 
// Module includes
#include "OnlineEventsFacebookCommon.h"
#include "OnlineSubsystemFacebookPackage.h"

class FOnlineSubsystemFacebookCustom;

/**
 * Facebook implementation of the Online User Interface
 */
class FOnlineEventsFacebook : public FOnlineEventsFacebookCommon
{

public:
	
	virtual bool TriggerEvent( const FUniqueNetId& PlayerId, const TCHAR* EventName, const FOnlineEventParms& Parms ) override;
	virtual void SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId) override;
	// FOnlineUserFacebook

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
