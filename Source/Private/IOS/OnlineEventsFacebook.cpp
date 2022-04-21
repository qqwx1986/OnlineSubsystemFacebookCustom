// Copyright Epic Games, Inc. All Rights Reserved.

// Module includes
#include "OnlineEventsFacebook.h"
#include "OnlineSubsystemFacebookPrivate.h"

// FOnlineUserFacebook

FOnlineEventsFacebook::FOnlineEventsFacebook(FOnlineSubsystemFacebookCustom* InSubsystem)
	: FOnlineEventsFacebookCommon(InSubsystem)
{
}

FOnlineEventsFacebook::~FOnlineEventsFacebook()
{

}
bool FOnlineEventsFacebook::TriggerEvent(const FUniqueNetId& PlayerId, const TCHAR* EventName,
										 const FOnlineEventParms& Parms)
{
	return false;
}

void FOnlineEventsFacebook::SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId)
{
}