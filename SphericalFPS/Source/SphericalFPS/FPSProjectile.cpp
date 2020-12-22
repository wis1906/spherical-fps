// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProjectile.h"

using namespace std;
using namespace cv;

// Sets default values
AFPSProjectile::AFPSProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ��ü�� �ܼ� �ݸ��� ǥ������ ����մϴ�.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);

	// ��ü�� �ݸ��� �ݰ��� �����մϴ�.
	CollisionComponent->InitSphereRadius(15.0f);
	// ��Ʈ ������Ʈ�� �ݸ��� ������Ʈ�� �����մϴ�.
	RootComponent = CollisionComponent;

	// ProjectileMovementComponent �� ����Ͽ� �� �߻�ü�� ��� �����մϴ�.
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// 5 �� �� �׽��ϴ�.
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
	//���� ���ϱ�
	depthVal = 255 - pReader->getPanoPointDepth(rot_theta, rot_phi);

	// �Ÿ��� ���� ���� �ð� ����
	float depthRatio = ((float)depthVal / 255);
	if (depthVal >= depthTheshold)
		LifeSpawnByDepth = 10.0f;
	else
		LifeSpawnByDepth = minLifeSpawn + (maxLifeSpawn - minLifeSpawn) * depthRatio;
	setLifeTimerByDepth(LifeSpawnByDepth);

	// �������� ��ġ�� ����
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
	// ��ġ ���ϱ�
	targetPatch = pReader->getPatchFromPanorama(rot_theta, rot_phi);
	if (pReader->isShowPanoImage)
		imshow("patch rgb", targetPatch);

	// �׷���ȭ
	Mat patchGray;
	cvtColor(targetPatch, patchGray, 6);

	// cs-lbp
	Mat patchCSLBP = pReader->getCSLBPImage(patchGray);

	if (pReader->isShowPanoImage)
		pReader->showCSLBPIamge("patch cslbp", patchCSLBP);

	// ������׷�
	vector<float> patchHist = pReader->getCSLBPHistogramNorm(patchCSLBP);

	// ��Ī
	int idx = pReader->compareCSLBPHistogramWithMaterial(patchHist);

	UE_LOG(SphericalFPS, Warning, TEXT("idx : %d"), idx);

	return idx;
}


//#########################
// Physics
//#########################
// ������Ÿ���� �ӵ��� �߻� �������� �ʱ�ȭ��Ű�� �Լ��Դϴ�.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// ������Ÿ�Ͽ� ���� ������ ȣ��Ǵ� �Լ��Դϴ�.
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
}