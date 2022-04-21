// Copyright Epic Games, Inc. All Rights Reserved.

#include "OnlineSubsystemFacebookCustom.h"
#include "OnlineSubsystemFacebookPrivate.h"
#include "OnlineIdentityFacebook.h"
#include "OnlineFriendsFacebook.h"
#include "OnlineSharingFacebook.h"
#include "OnlineEventsFacebook.h"

FOnlineSubsystemFacebookCustom::FOnlineSubsystemFacebookCustom(FName InInstanceName)
	: FOnlineSubsystemFacebookCommon(InInstanceName)
{
}

FOnlineSubsystemFacebookCustom::~FOnlineSubsystemFacebookCustom()
{
}

bool FOnlineSubsystemFacebookCustom::Init()
{
#if WITH_FACEBOOK
	FacebookIdentity = MakeShareable(new FOnlineIdentityFacebook(this));
	FacebookFriends = MakeShareable(new FOnlineFriendsFacebook(this));
	FacebookSharing = MakeShareable(new FOnlineSharingFacebook(this));
	FacebookEvents = MakeShareable(new FOnlineEventsFacebook(this));
	return true;
#else
	return false;
#endif
}

bool FOnlineSubsystemFacebookCustom::Shutdown()
{
	UE_LOG_ONLINE(VeryVerbose, TEXT("FOnlineSubsystemFacebookCustom::Shutdown()"));
	return FOnlineSubsystemFacebookCommon::Shutdown();
}

bool FOnlineSubsystemFacebookCustom::IsEnabled() const
{
	// Overridden due to different platform implementations of IsEnabled
	return FOnlineSubsystemFacebookCommon::IsEnabled();
}
