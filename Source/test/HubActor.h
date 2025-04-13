// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HubActor.generated.h"

class AMyActor;

UCLASS()
class TEST_API AHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	const int32 TotalCount = 10;
	int32 CurrentTimerCount = 0;

	UPROPERTY()
	TArray<AMyActor*> SpawnedObjects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMyActor> CppClass;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
