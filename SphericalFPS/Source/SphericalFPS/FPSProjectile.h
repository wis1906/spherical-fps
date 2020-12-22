// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SphericalFPS.h"
#include "Engine.h"
#include "panoramaReader.h"
#include "opencv2/opencv.hpp"
#include "GameFramework/Actor.h"
#include "FPSProjectile.generated.h"

UCLASS()
class SPHERICALFPS_API AFPSProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 구체 콜리전 컴포넌트입니다.
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	// 프로젝타일 무브먼트 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;

	// 구체가 발사될 당시의 카메라 회전값
	UPROPERTY(EditAnywhere, Category = Movement)
		FRotator initialRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<USoundBase*> soundsByMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UParticleSystem*> effectsByMaterial;

	ApanoramaReader* pReader;
	cv::Mat targetPatch;

	float rot_theta;
	float rot_phi;
	UPROPERTY(BlueprintReadWrite)
		int depthVal;
	float LifeSpawnByDepth;

	// 소리 피치값
	UPROPERTY(BlueprintReadWrite)
		float soundPitchVal;

	float minLifeSpawn = 0.3f;
	float maxLifeSpawn = 2.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int depthTheshold = 180;

	void SetInitialRotation(const FRotator& rot);
	void getThetaPhiByInitialRotation();
	void getDepth();
	UFUNCTION(BlueprintCallable, Category = Cubemap)
		int getPatch();

	// 발사체의 속도를 발사 방향으로 초기화시킵니다.
	void FireInDirection(const FVector& ShootDirection);

	// 프로젝타일이 무언가에 맞으면 호출되는 함수입니다.
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	//For blueprint functions
	UFUNCTION(BlueprintImplementableEvent, Category = Cubemap)
		void setLifeTimerByDepth(float lifeTime);
};
