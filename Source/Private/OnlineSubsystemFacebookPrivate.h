// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "Http.h"

#include "OnlineSubsystemFacebookCustom.h"
#include "OnlineSubsystemFacebookCustomModule.h"

/** pre-pended to all Facebook logging */
#undef ONLINE_LOG_PREFIX
#define ONLINE_LOG_PREFIX TEXT("Facebook: ")
