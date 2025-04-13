// Fill out your copyright notice in the Description page of Project Settings.


#include "HubActor.h"
#include "TimerManager.h"
#include "MyActor.h"

// Sets default values
AHubActor::AHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHubActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AHubActor::OnTimeToSpawn, SpawnTimerRate, true);
}

void AHubActor::OnTimeToSpawn()
{
	if (++CurrentTimerCount <= TotalCount)
	{
		const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.0f,1000.0f),
			FMath::FRandRange(200.0f,1000.0f),0.0f);
		const FRotator Rotation = FRotator::ZeroRotator;
		AMyActor* SpawnedObject = GetWorld()->SpawnActor<AMyActor>(CppClass, Location, Rotation);
		if (SpawnedObject)
		{
			SpawnedObjects.Add(SpawnedObject);
		}
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
		for (int i = TotalCount; i >= 1; --i)
		{
			GetWorldTimerManager().SetTimer(DestroyTimerHandle, this, &AHubActor::OnTimeToDestroy, DestroyTimerRate, true);
		}
	}
}

void AHubActor::OnTimeToDestroy()
{
	if (!SpawnedObjects.IsEmpty())
	{
		SpawnedObjects.Top()->Destroy();
		SpawnedObjects.Pop();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DestroyTimerHandle);
	}
}

// Called every frame
void AHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

