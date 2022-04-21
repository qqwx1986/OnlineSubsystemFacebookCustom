// Copyright Epic Games, Inc. All Rights Reserved.

#if USES_RESTFUL_FACEBOOK

#include "OnlineSubsystemFacebookCustom.h"
#include "OnlineSubsystemFacebookPrivate.h"
#include "OnlineIdentityFacebookRest.h"
#include "OnlineFriendsFacebookRest.h"
#include "OnlineSharingFacebookRest.h"
#include "OnlineEventsFacebookRest.h"
#include "OnlineExternalUIInterfaceFacebookRest.h"

FOnlineSubsystemFacebookCustom::FOnlineSubsystemFacebookCustom(FName InInstanceName)
	: FOnlineSubsystemFacebookCommon(InInstanceName)
{
}

FOnlineSubsystemFacebookCustom::~FOnlineSubsystemFacebookCustom()
{
}

bool FOnlineSubsystemFacebookCustom::Init()
{
	if (FOnlineSubsystemFacebookCommon::Init())
	{
		FacebookIdentity = MakeShareable(new FOnlineIdentityFacebook(this));
		FacebookFriends = MakeShareable(new FOnlineFriendsFacebook(this));
		FacebookExternalUI = MakeShareable(new FOnlineExternalUIFacebook(this));
		FacebookSharing = MakeShareable(new FOnlineSharingFacebook(this));
		FacebookEvents = MakeShareable(new FOnlineEventsFacebook(this));
		return true;
	}

	return false;
}

bool FOnlineSubsystemFacebookCustom::Shutdown()
{
	UE_LOG_ONLINE(Display, TEXT("FOnlineSubsystemFacebookCustom::Shutdown()"));
	return FOnlineSubsystemFacebookCommon::Shutdown();
}

bool FOnlineSubsystemFacebookCustom::IsEnabled() const
{
	// Overridden due to different platform implementations of IsEnabled
	return FOnlineSubsystemFacebookCommon::IsEnabled();
}

#endif // USES_RESTFUL_FACEBOOK
