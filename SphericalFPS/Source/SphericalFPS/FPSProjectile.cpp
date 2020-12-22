// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProjectile.h"

using namespace std;
using namespace cv;

// Sets default values
AFPSProjectile::AFPSProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 구체를 단순 콜리전 표현으로 사용합니다.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);

	// 구체의 콜리전 반경을 설정합니다.
	CollisionComponent->InitSphereRadius(15.0f);
	// 루트 컴포넌트를 콜리전 컴포넌트로 설정합니다.
	RootComponent = CollisionComponent;

	// ProjectileMovementComponent 를 사용하여 이 발사체의 운동을 관장합니다.
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// 5 초 후 죽습니다.
	//InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


//#########################
// Patch & Depth
//#########################
void AFPSProjectile::SetInitialRotation(const FRotator& rot)
{
	initialRotation = rot;
	getThetaPhiByInitialRotation();
}
void AFPSProjectile::getThetaPhiByInitialRotation()
{
	// get theta
	if (initialRotation.Pitch < 90)
		rot_theta = initialRotation.Pitch;
	else
		rot_theta = initialRotation.Pitch - 360;

	// get phi
	if (initialRotation.Yaw < 180)
		rot_phi = initialRotation.Yaw;
	else
		rot_phi = initialRotation.Yaw - 360;

	//UE_LOG(SphericalFPS, Warning, TEXT("Theta = %f, Phi = %f"), rot_theta, rot_phi);
}
void AFPSProjectile::getDepth()
{
	//뎁스 구하기
	depthVal = 255 - pReader->getPanoPointDepth(rot_theta, rot_phi);

	// 거리에 따른 폭파 시간 결정
	float depthRatio = ((float)depthVal / 255);
	if (depthVal >= depthTheshold)
		LifeSpawnByDepth = 10.0f;
	else
		LifeSpawnByDepth = minLifeSpawn + (maxLifeSpawn - minLifeSpawn) * depthRatio;
	setLifeTimerByDepth(LifeSpawnByDepth);

	// 폭파음의 피치값 결정
	if (depthRatio < 0.3f)
		soundPitchVal = 0.1;
	else if (depthRatio < 0.7f)
		soundPitchVal = 1;
	else
		soundPitchVal = 5;

	UE_LOG(SphericalFPS, Warning, TEXT("DepthVal = %d"), depthVal);
	//UE_LOG(SphericalFPS, Warning, TEXT("depthRatio = %f"), depthRatio);
	UE_LOG(SphericalFPS, Warning, TEXT("pitch = %f"), soundPitchVal);
}
int AFPSProjectile::getPatch()
{
	// 패치 구하기
	targetPatch = pReader->getPatchFromPanorama(rot_theta, rot_phi);
	if (pReader->isShowPanoImage)
		imshow("patch rgb", targetPatch);

	// 그레이화
	Mat patchGray;
	cvtColor(targetPatch, patchGray, 6);

	// cs-lbp
	Mat patchCSLBP = pReader->getCSLBPImage(patchGray);

	if (pReader->isShowPanoImage)
		pReader->showCSLBPIamge("patch cslbp", patchCSLBP);

	// 히스토그램
	vector<float> patchHist = pReader->getCSLBPHistogramNorm(patchCSLBP);

	// 매칭
	int idx = pReader->compareCSLBPHistogramWithMaterial(patchHist);

	UE_LOG(SphericalFPS, Warning, TEXT("idx : %d"), idx);

	return idx;
}


//#########################
// Physics
//#########################
// 프로젝타일의 속도를 발사 방향으로 초기화시키는 함수입니다.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// 프로젝타일에 무언가 맞으면 호출되는 함수입니다.
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
}