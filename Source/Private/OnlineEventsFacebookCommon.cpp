// Copyright Epic Games, Inc. All Rights Reserved.

#include "OnlineEventsFacebookCommon.h"
#if USES_RESTFUL_FACEBOOK
#include "OnlineEventsFacebookRest.h"
#else // USES_RESTFUL_FACEBOOK
#include "OnlineEventsFacebook.h"
#endif // USES_RESTFUL_FACEBOOK
#include "OnlineSubsystemFacebookPrivate.h"

FOnlineEventsFacebookCommon::FOnlineEventsFacebookCommon(FOnlineSubsystemFacebookCustom* InSubsystem)
	: FacebookSubsystem(InSubsystem)
{
}

bool FOnlineEventsFacebookCommon::TriggerEvent(const FUniqueNetId& PlayerId, const TCHAR* EventName,
	const FOnlineEventParms& Parms)
{
	return false;
}

void FOnlineEventsFacebookCommon::SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId)
{
}



