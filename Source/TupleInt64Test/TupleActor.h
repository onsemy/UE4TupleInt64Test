// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <tuple>

#include "TupleActor.generated.h"

UCLASS()
class TUPLEINT64TEST_API ATupleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATupleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int64_t TickCount = 0;
	float DeltaCount = 0.f;

	std::tuple<int32_t, uint8_t, int64_t> CheckPowerOfTwo(const int nNum);
	
};
