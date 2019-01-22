// Fill out your copyright notice in the Description page of Project Settings.

#include "TupleActor.h"


// Sets default values
ATupleActor::ATupleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATupleActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("ATupleActor::BeginPlay"));
}

// Called every frame
void ATupleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ((DeltaCount += DeltaTime) >= 1.f)
	{
		DeltaCount = 0.f;
		++TickCount;
		std::tuple<int32_t, uint8_t, int64_t> TupleTest = CheckPowerOfTwo(TickCount);
	}
}

std::tuple<int32_t, uint8_t, int64_t> ATupleActor::CheckPowerOfTwo(const int nNum)
{
	int nResult = nNum & (nNum - 1);

	if (nResult == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("ATupleActor::CheckPowerOfTwo - %d"), nResult);
		return std::make_tuple(nResult, 1, 1);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("ATupleActor::CheckPowerOfTwo - %d"), nResult);
		return std::make_tuple(nResult, 0, 0);
	}
}
