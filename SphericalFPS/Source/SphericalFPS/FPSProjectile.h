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

	// ��ü �ݸ��� ������Ʈ�Դϴ�.
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	// ������Ÿ�� �����Ʈ ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;

	// ��ü�� �߻�� ����� ī�޶� ȸ����
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

	// �Ҹ� ��ġ��
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

	// �߻�ü�� �ӵ��� �߻� �������� �ʱ�ȭ��ŵ�ϴ�.
	void FireInDirection(const FVector& ShootDirection);

	// ������Ÿ���� ���𰡿� ������ ȣ��Ǵ� �Լ��Դϴ�.
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	//For blueprint functions
	UFUNCTION(BlueprintImplementableEvent, Category = Cubemap)
		void setLifeTimerByDepth(float lifeTime);
};
