// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SphericalFPS.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"

#include "opencv2/opencv.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>

#include "panoramaReader.generated.h"

UENUM()
enum class PlayMode : uint8
{
	Image UMETA(DisplayName = "Image"),
	Video UMETA(DisplayName = "Video"),
};

UCLASS()
class SPHERICALFPS_API ApanoramaReader : public AActor
{
	GENERATED_BODY()

public:
	ApanoramaReader();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	//Editor Adjustable Field
	UPROPERTY(EditAnywhere, Category = Cubemap)
		int panoramaWidth = 3000;
	UPROPERTY(EditAnywhere, Category = Cubemap)
		int panoramaHeight = 1500;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cubemap)
		float viewRatio = 1.0f;
	UPROPERTY(EditAnywhere, Category = Cubemap)
		bool isShowPanoImage = false;
	UPROPERTY(EditAnywhere, Category = Cubemap)
		bool isShowPaintball = false;

	UPROPERTY(EditAnywhere, Category = Cubemap)
		FString filePath = "D:/Unreal_Project/4.19.2/SphericalFPS/Content/Images/";
	UPROPERTY(EditAnywhere, Category = Cubemap)
		FString imagePath_RGB = "pano_1_rgb.jpg";
	UPROPERTY(EditAnywhere, Category = Cubemap)
		FString imagePath_Depth = "pano_1_depth.jpg";
	//UPROPERTY(EditAnywhere, Category = Cubemap)
	std::vector< std::vector<FString>> imagePath_MaterialImg;

	UPROPERTY(EditAnywhere, Category = Cubemap)
		PlayMode playMode;

	int halfPatchSize = 50;

public:
	// bool flag
	bool isOpened = false;

	//Image Database
	class imageDatabase* imageData;

	//Material Data
	TArray<TArray<cv::Mat>> materialImgs;
	TArray<TArray<cv::Mat>> materialCSLBPImgs;
	TArray< TArray<std::vector<float>>> materialHistogramNorm;

	//Texture Data
	//------------------------------
	// The current texture array
	TArray<FColor> Data;
	// Pointer to update texture region 2D struct
	FUpdateTextureRegion2D* VideoUpdateTextureRegion;
	// Image textures
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* TopTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* BottomTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* RearTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* LeftTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* FrontTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap)
		UTexture2D* RightTexture;

public:

	//For File IO
	bool loadFile(imageDatabase* imgData);

	//For Init
	void initImageDatabase(imageDatabase* imageData, int width, int height);
	void initTexture(cv::Size size);

	//For Processing
	void doProcessing(imageDatabase* imgData);

	//For panorama to cubemap
	void createCubemap(imageDatabase* imgData);
	void cubeToImg(imageDatabase* imgData, cv::Mat* Img, char Type);
	cv::Point3d getPanoramaAxis(int x, int y, char Type, int CubeWidth, int Width, int Height);
	cv::Point3d getThetaPhi(double x, double y, double z);

	//For Texture Update
	void updateTextureAll(imageDatabase* imgdata);
	void updateTextureAtOneTime(cv::Size size, cv::Mat* image, UTexture2D* texture);

	//For blueprint functions
	UFUNCTION(BlueprintImplementableEvent, Category = Cubemap)
		void OnNextVideoFrame();

	//For patch processing
	cv::Mat getPatchFromPanorama(float lat, float lon);
	cv::Point2i getOriginAxis(int x, int y, double latitudeDegree, double longitudeDegree, cv::Size viewSize);
	cv::Point2i getPanoramaAxisForLatLon(int x, int y, double thetaPlus, double phiPlus, cv::Size viewSize, cv::Size panoSize);

	//For depth process
	int getPanoPointDepth(float latDegree, float lonDegree);
	cv::Point2d getPanoPointFromLatLon(float latDegree, float lonDegree);

	//For LBP process
	void showCSLBPIamge(std::string winsdowName, cv::Mat& img);
	int compareCSLBPHistogramWithMaterial(std::vector<float> hist);
	std::vector<float> getCSLBPHistogramNorm(cv::Mat& img);
	cv::Mat getCSLBPImage(cv::Mat& image);
	cv::Mat getLBPImage(cv::Mat& image);
	void createMaterialLBPImage();
};

class imageDatabase
{
public:
	cv::VideoCapture VCap_RGB;
	cv::VideoCapture VCap_Depth;

	cv::Size sz;

	cv::Mat sourceImg_RGB;
	cv::Mat sourceImg_Depth;
	cv::Mat panoramaImg_RGB;
	cv::Mat panoramaImg_Depth;
	cv::Mat panoramaImg_Gray;
	cv::Mat panoramaImg_LBP;

	cv::Mat TopImg;
	cv::Mat BottomImg;
	cv::Mat RearImg;
	cv::Mat LeftImg;
	cv::Mat FrontImg;
	cv::Mat RightImg;
};