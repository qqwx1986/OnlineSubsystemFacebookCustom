// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FacebookBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class ONLINESUBSYSTEMFACEBOOKCUSTOM_API UFacebookBlueprintFunctionLibrary : public UObject
{
	GENERATED_BODY()


public:
	//通用接口
	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void Events(const FString& EventName, const FString& JsonParams);

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventCompletedRegistration(const FString& Method);

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventSubmitApplication();

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventAchievedLevel(const FString& Level);

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventUnlockedAchievement(const FString& Description);

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventAddedPaymentInfo(int Success);

	UFUNCTION(BlueprintCallable, Category="FacebookBlueprintFunctionLibrary")
	static void EventCompletedTutorial(int Success,const FString& ContentId,const FString& Content);
};
