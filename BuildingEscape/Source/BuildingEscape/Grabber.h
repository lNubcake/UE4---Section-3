// Copyright Nubcake 2017

#pragma once

#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "Grabber.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Find attached physics
	void FindPhysicsHandleComponent();

	// Setup input component
	void SetupInputComponent();

	// Ray-cast and grab what's in reach
	void Grab();

	// Release what's grabbed
	void Release();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
