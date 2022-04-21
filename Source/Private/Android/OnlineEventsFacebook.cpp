// Copyright Epic Games, Inc. All Rights Reserved.

// Module includes
#include "OnlineEventsFacebook.h"
#include "OnlineSubsystemFacebookPrivate.h"
#include "OnlineIdentityFacebook.h"

#if WITH_FACEBOOK

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Async/TaskGraphInterfaces.h"

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
	UE_LOG(LogTemp, Log, TEXT("FOnlineEventsFacebook::TriggerEvent %s"), EventName);
	extern bool AndroidThunkCpp_Facebook_LogEvent(const FString& EventName, const FOnlineEventParms& Parms);
	return AndroidThunkCpp_Facebook_LogEvent(EventName, Parms);
}

void FOnlineEventsFacebook::SetPlayerSessionId(const FUniqueNetId& PlayerId, const FGuid& PlayerSessionId)
{
}

#define CHECK_JNI_METHOD(Id) checkf(Id != nullptr, TEXT("Failed to find " #Id));

bool AndroidThunkCpp_Facebook_LogEvent(const FString& EventName, const FOnlineEventParms& Params)
{
	UE_LOG(LogTemp, Log, TEXT("AndroidThunkCpp_Facebook_LogEvent Begin"));
	bool bSuccess = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;

		static jmethodID FacebookLogoutMethod = FJavaWrapper::FindMethod(
			Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Facebook_Logout", "()V", bIsOptional);
		static jmethodID FacebookLoginMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
		                                                                "AndroidThunkJava_Facebook_Login",
		                                                                "([Ljava/lang/String;)V", bIsOptional);
		static jmethodID FacebookLogEventMethod = FJavaWrapper::FindMethod(
			Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Facebook_LogEvent",
			"(Ljava/lang/String;Landroid/os/Bundle;)V", bIsOptional);

		static jclass Clz = FJavaWrapper::FindClass(Env, "android/os/Bundle", bIsOptional);
		static jmethodID ConstructorID = FJavaWrapper::FindMethod(Env, Clz, "<init>", "()V", bIsOptional);
		static jmethodID PutStringMethodId = FJavaWrapper::FindMethod(Env, Clz, "putString",
		                                                              "(Ljava/lang/String;Ljava/lang/String;)V",
		                                                              bIsOptional);
		static jmethodID PutDoubleMethodId = FJavaWrapper::FindMethod(Env, Clz, "putDouble", "(Ljava/lang/String;D)V",
		                                                              bIsOptional);
		static jmethodID PutBooleanMethodId = FJavaWrapper::FindMethod(Env, Clz, "putBoolean",
		                                                               "(Ljava/lang/String;Z)V", bIsOptional);
		static jmethodID PutIntMethodId = FJavaWrapper::FindMethod(Env, Clz, "putInt",
																	   "(Ljava/lang/String;I)V", bIsOptional);

		CHECK_JNI_METHOD(FacebookLogEventMethod);

		// Convert scope array into java fields
		auto ScopeObject = NewScopedJavaObject(
			Env, (jobject)Env->NewObject(Clz, ConstructorID));
		for (auto Param : Params)
		{
			auto Type = Param.Value.GetType();
			switch (Type)
			{
			case EOnlineKeyValuePairDataType::Type::String:
				{
					FString V;
					Param.Value.GetValue(V);
					FJavaWrapper::CallVoidMethod(Env, *ScopeObject, PutStringMethodId,
					                             *FJavaHelper::ToJavaString(Env, Param.Key),
					                             *FJavaHelper::ToJavaString(Env, V));
				}
				break;
			case EOnlineKeyValuePairDataType::Type::Bool:
				{
					bool V;
					Param.Value.GetValue(V);
					FJavaWrapper::CallVoidMethod(Env, *ScopeObject, PutBooleanMethodId,
					                             *FJavaHelper::ToJavaString(Env, Param.Key),
					                             V);
				}
				break;
			case EOnlineKeyValuePairDataType::Type::Double:
				{
					double V;
					Param.Value.GetValue(V);
					FJavaWrapper::CallVoidMethod(Env, *ScopeObject, PutDoubleMethodId,
					                             *FJavaHelper::ToJavaString(Env, Param.Key),
					                             V);
				}
				break;
			case EOnlineKeyValuePairDataType::Type::Int32:
			case EOnlineKeyValuePairDataType::Type::UInt32:
				{
					int V;
					Param.Value.GetValue(V);
					FJavaWrapper::CallVoidMethod(Env, *ScopeObject, PutIntMethodId,
					                             *FJavaHelper::ToJavaString(Env, Param.Key),
					                             V);
				}
				break;
			default:
				UE_LOG(LogTemp, Error, TEXT("Wrong type %s"), *Param.Key);
				break;
			}
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FacebookLogEventMethod,
		                             *FJavaHelper::ToJavaString(Env, EventName),
		                             Params.Num() > 0 ? *ScopeObject : nullptr);
		bSuccess = true;
	}
	UE_LOG(LogTemp, Log, TEXT("AndroidThunkCpp_Facebook_LogEvent %s"),bSuccess?TEXT("Succeed"):TEXT("Failed"));
	return bSuccess;
}


#endif // WITH_FACEBOOK
