// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OnlineEventsFacebookCommon.h"

#if USES_RESTFUL_FACEBOOK
 
// Module includes
#include "OnlineUserFacebookCommon.h"
#include "OnlineSubsystemFacebookPackage.h"

class FOnlineSubsystemFacebookCustom;

/**
 * Facebook implementation of the Online User Interface
 */
class FOnlineEventsFacebook : public FOnlineEventsFacebookCommon
{

public:
	
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

#endif // USES_RESTFUL_FACEBOOK