// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#if USES_RESTFUL_FACEBOOK
 
// Module includes
#include "OnlineUserFacebookCommon.h"
#include "OnlineSubsystemFacebookPackage.h"

class FOnlineSubsystemFacebookCustom;

/**
 * Facebook implementation of the Online User Interface
 */
class FOnlineUserFacebook : public FOnlineUserFacebookCommon
{

public:
	
	// FOnlineUserFacebook

	/**
	 * Constructor used to indicate which OSS we are a part of
	 */
	FOnlineUserFacebook(FOnlineSubsystemFacebookCustom* InSubsystem);
	
	/**
	 * Default destructor
	 */
	virtual ~FOnlineUserFacebook();

};

typedef TSharedPtr<FOnlineUserFacebook, ESPMode::ThreadSafe> FOnlineUserFacebookPtr;

#endif // USES_RESTFUL_FACEBOOK