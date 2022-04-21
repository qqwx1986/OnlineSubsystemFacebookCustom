// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Interfaces/OnlineEventsInterface.h"
#include "Interfaces/OnlineSharingInterface.h"
#include "OnlineSubsystemFacebookPackage.h"
#include "Interfaces/IHttpRequest.h"

class FOnlineSubsystemFacebookCustom;

/**
 * Facebook service implementation of the online events interface
 */
class FOnlineEventsFacebookCommon :
	public IOnlineEvents
{

protected:

	/** Parent subsystem */
	FOnlineSubsystemFacebookCustom* FacebookSubsystem;

public:
	/**
		 * Trigger an event by name
		 *
		 * @param PlayerId	- Player to trigger the event for
		 * @param EventName - Name of the event
		 * @param Parms		- The parameter list to be passed into the event
		 *
		 * @return Whether the event was successfully triggered
		 */
	virtual bool TriggerEvent( const FUniqueNetId& PlayerId, const TCHAR* EventName, const FOnlineEventParms& Parms ) override;

	/**
	 * Quick way to send a valid PlayerSessionId with every event, required for Xbox One
	 *
	 * @param PlayerId the unique id of the player this session is associated with
	 * @param PlayerSessionId A GUID unique to this player session
	 */
	virtual void SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId) override;

	// FOnlineIdentityFacebook

	FOnlineEventsFacebookCommon(FOnlineSubsystemFacebookCustom* InSubsystem);

	/**
	 * Destructor
	 */
	virtual ~FOnlineEventsFacebookCommon()
	{
	}


};

typedef TSharedPtr<FOnlineEventsFacebookCommon, ESPMode::ThreadSafe> FOnlineEventsFacebookCommonPtr;
