// Fill out your copyright notice in the Description page of Project Settings.


#include "FacebookBlueprintFunctionLibrary.h"

#include "OnlineSubsystem.h"
#include "OnlineSubsystemModule.h"
#include "OnlineSubsystemNames.h"
#include "Interfaces/OnlineEventsInterface.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

//事件类型
UENUM(BlueprintType)
enum class EFacebookEventName : uint8
{
	None = 0,
	CompletedRegistration = 1,
	SubmitApplication = 2,
	CompletedTutorial = 3,
	AchievedLevel = 4,
	UnlockedAchievement = 5,
	AddedPaymentInfo = 6,
};

static const FString EVENT_NAME_COMPLETED_REGISTRATION = "fb_mobile_complete_registration";
static const FString EVENT_NAME_SUBMIT_APPLICATION = "SubmitApplication";
static const FString EVENT_NAME_COMPLETED_TUTORIAL = "fb_mobile_tutorial_completion";
static const FString EVENT_NAME_ACHIEVED_LEVEL = "fb_mobile_level_achieved";
static const FString EVENT_NAME_UNLOCKED_ACHIEVEMENT = "fb_mobile_achievement_unlocked";
static const FString EVENT_NAME_ADDED_PAYMENT_INFO = "fb_mobile_add_payment_info";


static const FString EVENT_PARAM_REGISTRATION_METHOD = "fb_registration_method";
static const FString EVENT_PARAM_LEVEL = "fb_level";
static const FString EVENT_PARAM_DESCRIPTION = "fb_description";
static const FString EVENT_PARAM_SUCCESS = "fb_success";
static const FString EVENT_PARAM_CONTENT_ID = "fb_content_id";
static const FString EVENT_PARAM_CONTENT = "fb_content";
static FUniqueNetIdString NullID;

static IOnlineEventsPtr GetEvents()
{
	FOnlineSubsystemModule& OSS = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	static FString FullName = FACEBOOK_SUBSYSTEM.ToString() + TEXT(":FacebookCustom");
	IOnlineSubsystem* System = OSS.GetOnlineSubsystem(FName(FullName));
	return System->GetEventsInterface();
}

void UFacebookBlueprintFunctionLibrary::Events(const FString& EventName, const FString& JsonParams)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::Events %s,%s"), *EventName, *JsonParams);
	FOnlineEventParms Parms;
	if (JsonParams.Len() > 0)
	{
		TSharedRef<TJsonReader<TCHAR>> Reader = FJsonStringReader::Create(JsonParams);

		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			UE_LOG(LogTemp, Error, TEXT("UFacebookBlueprintFunctionLibrary::Events Failed %s %s"), *EventName,
			       *JsonParams);
			return;
		}
		for (auto Value : JsonObject->Values)
		{
			switch (Value.Value->Type)
			{
			case EJson::Boolean:
				Parms.Add(Value.Key, Value.Value->AsBool());
				break;
			case EJson::String:
				Parms.Add(Value.Key, Value.Value->AsString());
				break;
			case EJson::Number:
				Parms.Add(Value.Key, Value.Value->AsNumber());
				break;
			default:
				break;
			}
		}
	}
	GetEvents()->TriggerEvent(NullID, *EventName, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventCompletedRegistration(const FString& Method)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventCompletedRegistration %s"), *Method);
	FOnlineEventParms Parms;
	Parms.Add(EVENT_PARAM_REGISTRATION_METHOD, Method);
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_COMPLETED_REGISTRATION, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventSubmitApplication()
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventSubmitApplication"));
	FOnlineEventParms Parms;
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_SUBMIT_APPLICATION, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventAchievedLevel(const FString& Level)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventAchievedLevel %s"), *Level);
	FOnlineEventParms Parms;
	Parms.Add(EVENT_PARAM_LEVEL, Level);
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_ACHIEVED_LEVEL, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventUnlockedAchievement(const FString& Description)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventUnlockedAchievement %s"), *Description);
	FOnlineEventParms Parms;
	Parms.Add(EVENT_PARAM_DESCRIPTION, Description);
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_UNLOCKED_ACHIEVEMENT, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventAddedPaymentInfo(int Success)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventAddedPaymentInfo %d"), Success);
	FOnlineEventParms Parms;
	Parms.Add(EVENT_PARAM_SUCCESS, Success);
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_ADDED_PAYMENT_INFO, Parms);
}

void UFacebookBlueprintFunctionLibrary::EventCompletedTutorial(int Success, const FString& ContentId,
                                                               const FString& Content)
{
	UE_LOG(LogTemp, Log, TEXT("UFacebookBlueprintFunctionLibrary::EventCompletedTutorial %d,%s,%s"), Success,
	       *ContentId, *Content);
	FOnlineEventParms Parms;
	Parms.Add(EVENT_PARAM_SUCCESS, Success);
	Parms.Add(EVENT_PARAM_CONTENT_ID, ContentId);
	Parms.Add(EVENT_PARAM_CONTENT, Content);
	GetEvents()->TriggerEvent(NullID, *EVENT_NAME_COMPLETED_TUTORIAL, Parms);
}
