// Copyright Epic Games, Inc. All Rights Reserved.

#if USES_RESTFUL_FACEBOOK

#include "OnlineEventsFacebookRest.h"
#include "OnlineSubsystemFacebookPrivate.h"

FOnlineEventsFacebook::FOnlineEventsFacebook(FOnlineSubsystemFacebookCustom* InSubsystem)
	: FOnlineEventsFacebookCommon(InSubsystem)
{
}

FOnlineEventsFacebook::~FOnlineEventsFacebook()
{
}

#endif // USES_RESTFUL_FACEBOOK
