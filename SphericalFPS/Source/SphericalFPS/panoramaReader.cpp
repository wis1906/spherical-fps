// Fill out your copyright notice in the Description page of Project Settings.

#include "panoramaReader.h"

using namespace std;
using namespace cv;

// Sets default values
ApanoramaReader::ApanoramaReader()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Init class
	imageData = new imageDatabase();
}

// Called when the game starts or when spawned
void ApanoramaReader::BeginPlay()
{
	Super::BeginPlay();

	//Initialize
	initImageDatabase(imageData, panoramaWidth, panoramaHeight);
	initTexture(imageData->sz);

	//Load File
	if (!loadFile(imageData))
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Input file not found."));

	//load Material Images
	for (int i = 0; i < 4; i++)
	{
		vector<FString> vec;
		imagePath_MaterialImg.push_back((vec));
	}
	imagePath_MaterialImg[0].push_back("material_concrete.png");
	imagePath_MaterialImg[0].push_back("material_concrete2.png");
	imagePath_MaterialImg[0].push_back("material_concrete3.png");
	imagePath_MaterialImg[0].push_back("material_concrete4.png");
	//imagePath_MaterialImg[0].push_back("material_concrete5.png");
	imagePath_MaterialImg[1].push_back("material_grass.png");
	imagePath_MaterialImg[1].push_back("material_grass2.png");
	imagePath_MaterialImg[1].push_back("material_grass3.png");
	imagePath_MaterialImg[1].push_back("material_grass4.png");
	//imagePath_MaterialImg[1].push_back("material_grass5.png");
	imagePath_MaterialImg[2].push_back("material_tile.png");
	imagePath_MaterialImg[2].push_back("material_tile2.png");
	imagePath_MaterialImg[2].push_back("material_tile3.png");
	imagePath_MaterialImg[2].push_back("material_tile4.png");
	//imagePath_MaterialImg[2].push_back("material_tile5.png");
	imagePath_MaterialImg[3].push_back("material_wood.png");
	imagePath_MaterialImg[3].push_back("material_wood2.png");
	imagePath_MaterialImg[3].push_back("material_wood3.png");
	imagePath_MaterialImg[3].push_back("material_wood4.png");
	//imagePath_MaterialImg[3].push_back("material_wood5.png");
	createMaterialLBPImage();

	//Processing for image
	if (isOpened && playMode == PlayMode::Image)
		doProcessing(imageData);
}

// Called every frame
void ApanoramaReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Process video frame per tick
	if (isOpened && playMode == PlayMode::Video)
	{
		if (!imageData->VCap_RGB.read(imageData->sourceImg_RGB))
		{	//Restart Video
			FString pathString = filePath + imagePath_RGB;
			imageData->VCap_RGB = VideoCapture(TCHAR_TO_UTF8(*pathString));
			imageData->VCap_RGB.set(CAP_PROP_FRAME_WIDTH, panoramaWidth);
			imageData->VCap_RGB.set(CAP_PROP_FRAME_HEIGHT, panoramaHeight);
			imageData->VCap_RGB.read(imageData->sourceImg_RGB);
		}
		if (!imageData->VCap_Depth.read(imageData->sourceImg_Depth))
		{	//Restart Video
			FString pathString = filePath + imagePath_Depth;
			imageData->VCap_Depth = VideoCapture(TCHAR_TO_UTF8(*pathString));
			imageData->VCap_Depth.set(CAP_PROP_FRAME_WIDTH, panoramaWidth);
			imageData->VCap_Depth.set(CAP_PROP_FRAME_HEIGHT, panoramaHeight);
			imageData->VCap_Depth.read(imageData->sourceImg_Depth);
		}

		doProcessing(imageData);

	}
}

//###############################
// Processing
//###############################
void ApanoramaReader::doProcessing(imageDatabase* imgData)
{
	//Get panorama image
	resize(imgData->sourceImg_RGB, imgData->panoramaImg_RGB, Size(panoramaWidth, panoramaHeight));
	resize(imgData->sourceImg_Depth, imgData->panoramaImg_Depth, Size(panoramaWidth, panoramaHeight));

	//Get gray & CS LBP image
	cvtColor(imgData->panoramaImg_RGB, imgData->panoramaImg_Gray, 6);
	imgData->panoramaImg_LBP = getCSLBPImage(imgData->panoramaImg_Gray);

	//Create Cubemap
	createCubemap(imageData);

	//Update Texture
	updateTextureAll(imageData);

	//Update VideoFrame(For Blueprint)
	OnNextVideoFrame();
}


//###############################
// Panorama to Cubemap
//###############################
void ApanoramaReader::createCubemap(imageDatabase* imgData)
{
	cubeToImg(imgData, &imgData->RearImg, 'A');
	cubeToImg(imgData, &imgData->LeftImg, 'L');
	cubeToImg(imgData, &imgData->FrontImg, 'F');
	cubeToImg(imgData, &imgData->RightImg, 'R');
	cubeToImg(imgData, &imgData->TopImg, 'T');
	cubeToImg(imgData, &imgData->BottomImg, 'B');
}
void ApanoramaReader::cubeToImg(imageDatabase* imgData, Mat* Img, char Type)
{
	int width = Img->cols;
	int height = Img->rows;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Point3d xy = getPanoramaAxis(j, i, Type, width, imgData->panoramaImg_RGB.cols, imgData->panoramaImg_RGB.rows);

			int idx = j + (i * width);
			int xy_idx = (int)xy.x + ((int)xy.y * panoramaWidth);

			//Img->at<Vec3b>(Point(j, i)) = imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y));
			Img->data[idx * 3 + 0] = imgData->panoramaImg_RGB.data[xy_idx * 3 + 0];
			Img->data[idx * 3 + 1] = imgData->panoramaImg_RGB.data[xy_idx * 3 + 1];
			Img->data[idx * 3 + 2] = imgData->panoramaImg_RGB.data[xy_idx * 3 + 2];
		}
	}
}
Point3d ApanoramaReader::getPanoramaAxis(int x, int y, char Type, int CubeWidth, int Width, int Height)
{
	double u = 2 * (double(x) / CubeWidth - 0.5f);
	double v = 2 * (double(y) / CubeWidth - 0.5f);

	Point3d ThetaPhi;
	if (Type == 'F')
	{
		ThetaPhi = getThetaPhi(1, u, -v);
	}
	else if (Type == 'R')
	{
		ThetaPhi = getThetaPhi(-u, 1, -v);
	}
	else if (Type == 'L')
	{
		ThetaPhi = getThetaPhi(u, -1, -v);
	}
	else if (Type == 'A')
	{
		ThetaPhi = getThetaPhi(-1, -u, -v);
	}
	else if (Type == 'B')
	{
		ThetaPhi = getThetaPhi(-v, u, -1);
	}
	else if (Type == 'T')
	{
		ThetaPhi = getThetaPhi(v, u, 1);
	}

	double _x;
	double _y;
	_x = 0.5 + 0.5*(ThetaPhi.x / PI);
	_y = (ThetaPhi.y / PI);

	Point3d xy;
	xy.x = _x * Width;
	xy.y = _y * Height;
	if (xy.x < 0)
		xy.x = 0;
	if (xy.x >= Width)
		xy.x = Width - 1;
	if (xy.y < 0)
		xy.y = 0;
	if (xy.y >= Height)
		xy.y = Height - 1;
	return xy;
}
Point3d ApanoramaReader::getThetaPhi(double x, double y, double z)
{
	double dv = sqrt(x * x + y * y + z * z);
	x = x / dv;
	y = y / dv;
	z = z / dv;

	Point3d ThetaPhi;
	ThetaPhi.x = atan2(y, x);
	ThetaPhi.y = acos(z);
	return ThetaPhi;
}

//###############################
// Patch Process
//###############################
Mat ApanoramaReader::getPatchFromPanorama(float latDegree, float lonDegree)
{
	int patchSize = 2 * halfPatchSize + 1;
	int levelHeight = imageData->sz.height * 2;
	int levelWidth = imageData->sz.width * 4;
	int projectionSize = levelHeight / 2;

	Mat patchImg = Mat(Size(patchSize, patchSize), CV_8UC3, Scalar(0, 0, 0));

	for (int patchX = 0; patchX < patchSize; patchX++)
	{
		for (int patchY = 0; patchY < patchSize; patchY++)
		{
			//투영 패치 좌표
			Point2d imagepointerRef;
			imagepointerRef.x = projectionSize / 2 + patchX - halfPatchSize;
			imagepointerRef.y = projectionSize / 2 + patchY - halfPatchSize;

			//파노라마에서의 좌표 추출
			Point2i xy = getOriginAxis(imagepointerRef.x, imagepointerRef.y, latDegree, lonDegree, Size(projectionSize, projectionSize));

			//if (patchX == 0 && patchY == 0)
			//	UE_LOG(SphericalFPS, Warning, TEXT("x = %d, y = %d"), xy.x, xy.y);

			int idx = patchX + (patchY * patchSize);
			int xy_idx = xy.x + (xy.y * levelWidth);


			//patchImg.at<Vec3b>(Point(patchX, patchY)) = imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y));
			patchImg.data[idx * 3 + 0] = imageData->panoramaImg_RGB.data[xy_idx * 3 + 0];
			patchImg.data[idx * 3 + 1] = imageData->panoramaImg_RGB.data[xy_idx * 3 + 1];
			patchImg.data[idx * 3 + 2] = imageData->panoramaImg_RGB.data[xy_idx * 3 + 2];

			if (isShowPaintball)
			{
				//imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y))[0] = 255;
				//imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y))[0] = 0;
				//imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y))[0] = 0;
				imageData->panoramaImg_RGB.data[xy_idx * 3 + 0] = 255;
				imageData->panoramaImg_RGB.data[xy_idx * 3 + 1] = 0;
				imageData->panoramaImg_RGB.data[xy_idx * 3 + 2] = 0;
			}
		}
	}

	if (isShowPanoImage)
		imshow("Panorama Image", imageData->panoramaImg_RGB);

	if (isShowPaintball)
	{
		//Create Cubemap
		createCubemap(imageData);

		//Update Texture
		updateTextureAll(imageData);

		//Update VideoFrame(For Blueprint)
		OnNextVideoFrame();
	}

	return patchImg;
}
Point2i ApanoramaReader::getOriginAxis(int x, int y, double latitudeDegree, double longitudeDegree, Size viewSize)
{
	double thetaPlus = -latitudeDegree * (2 * CV_PI / 360);
	double phiPlus = longitudeDegree * (2 * CV_PI / 360);

	Size sourceSize;
	sourceSize.width = viewSize.width * 4;
	sourceSize.height = sourceSize.width / 2;

	Point2i xy = getPanoramaAxisForLatLon(x, y, thetaPlus, phiPlus, viewSize, sourceSize);



	return xy;
}
Point2i ApanoramaReader::getPanoramaAxisForLatLon(int x, int y, double thetaPlus, double phiPlus, Size viewSize, Size panoSize)
{
	double u, v;

	u = 2 * (double(x) / viewSize.width - 0.5f);
	v = 2 * (double(y) / viewSize.height - 0.5f);


	Point3d ThetaPhi;

	//기본 프로젝터
	double x1 = 1;
	double y1 = u;
	double z1 = -v;


	//y축 회전 변환
	double x2 = x1 * cos(thetaPlus) + z1 * sin(thetaPlus);
	double y2 = y1;
	double z2 = -x1 * sin(thetaPlus) + z1 * cos(thetaPlus);

	//z축 회전 변환
	double x3 = x2 * cos(phiPlus) - y2 * sin(phiPlus);
	double y3 = x2 * sin(phiPlus) + y2 * cos(phiPlus);
	double z3 = z2;


	ThetaPhi = getThetaPhi(x3, y3, z3);


	double _x;
	double _y;
	_x = 0.5 + 0.5*(ThetaPhi.x / CV_PI);
	_y = (ThetaPhi.y / CV_PI);

	Point2i xy;
	xy.x = (int)(_x * panoSize.width);
	xy.y = (int)(_y * panoSize.height);
	if (xy.x < 0)
		xy.x = 0;
	if (xy.x >= panoSize.width - 1)
		xy.x = panoSize.width - 2;
	if (xy.y < 0)
		xy.y = 0;
	if (xy.y >= panoSize.height - 1)
		xy.y = panoSize.height - 2;

	return xy;
}

//###############################
// Depth Process
//###############################
int ApanoramaReader::getPanoPointDepth(float latDegree, float lonDegree)
{
	Point2d xy = getPanoPointFromLatLon(latDegree, lonDegree);

	Vec3b c = imageData->panoramaImg_Depth.at<Vec3b>(Point(xy.x, xy.y));
	int depthVal = c[0];

	return depthVal;
}
Point2d ApanoramaReader::getPanoPointFromLatLon(float latDegree, float lonDegree)
{
	int panoWidth = imageData->sz.width * 4;
	int panoHeight = panoWidth / 2;

	float xRatio = (lonDegree + 180) / 360;
	float yRatio = -(latDegree - 90) / 180;

	Point2d xy;
	xy.x = (int)((float)panoWidth*xRatio);
	xy.y = (int)((float)panoHeight*yRatio);

	return xy;
}

//###############################
// LBP Process
//###############################
void ApanoramaReader::showCSLBPIamge(string windowName, Mat& img)
{
	double maxVal = 0;
	minMaxLoc(img, NULL, &maxVal);
	Mat imgToShow = img / maxVal * 255;
	imshow(windowName, imgToShow);
}
int ApanoramaReader::compareCSLBPHistogramWithMaterial(vector<float> hist)
{
	int bestIdx = 0;
	float bestAcc = 99999.0f;
	for (int i = 0; i < materialHistogramNorm.Num(); i++)
	{
		float diffSum = 0;
		for (int j = 0; j < materialHistogramNorm[i].Num(); j++)
		{
			for (int k = 0; k < 15; k++)
				diffSum += (hist[k] - materialHistogramNorm[i][j][k])*(hist[k] - materialHistogramNorm[i][j][k]);
		}

		UE_LOG(SphericalFPS, Warning, TEXT("idx %d diffSum : %f"), i, diffSum);

		float diffMean = diffSum / materialHistogramNorm[i].Num();
		if (diffMean < bestAcc)
		{
			bestIdx = i;
			bestAcc = diffMean;
		}
	}

	return bestIdx;
}
vector<float> ApanoramaReader::getCSLBPHistogramNorm(Mat& img)
{
	int nr = img.rows;
	int nc = img.cols;

	vector<int> result;
	for (int i = 0; i < 300; i++)
		result.push_back(0);
	vector<float> resultNorm;
	for (int i = 0; i < 300; i++)
		resultNorm.push_back(0.0f);

	for (int i = 1; i < nr - 1; i++) {
		for (int j = 1; j < nc - 1; j++) {
			uchar val = img.at<uchar>(i, j);
			result[val] ++;
		}
	}

	int resultSum = 0;
	for (int i = 0; i < 15; i++)
	{
		resultSum += result[i];
	}
	float normSum = 0.0f;
	for (int i = 0; i < 15; i++)
	{
		resultNorm[i] = (float)result[i] / resultSum;
		normSum += resultNorm[i];
	}

	UE_LOG(SphericalFPS, Warning, TEXT("histogram : %f %f %f %f %f %f %f %f"), resultNorm[0],resultNorm[1], resultNorm[2], resultNorm[3], resultNorm[4], resultNorm[5], resultNorm[6], resultNorm[7]);
	return resultNorm;
}
Mat ApanoramaReader::getCSLBPImage(Mat& image)
{
	int nr = image.rows;
	int nc = image.cols;
	int unit = 3;
	Mat result(image.size(), CV_8U, Scalar(0));

	for (int i = unit; i < nr - unit; i++) {
		const uchar* prevRow = image.ptr<uchar>(i - unit);
		const uchar* currRow = image.ptr<uchar>(i);
		const uchar* nextRow = image.ptr<uchar>(i + unit);

		for (int j = unit; j < nc - unit; j++) {
			uchar resPix = 0;
			resPix |= (currRow[j + unit] >= currRow[j - unit]) << 3; //V4-V8
			resPix |= (prevRow[j + unit] >= nextRow[j - unit]) << 2; //V3-V7
			resPix |= (prevRow[j] >= nextRow[j]) << 1; //V2-V6
			resPix |= (prevRow[j - unit] >= nextRow[j + unit]);  //V1-V5
			result.at<uchar>(i, j) = resPix;
		}
	}
	return result;
}
Mat ApanoramaReader::getLBPImage(Mat& image) {

	int nr = image.rows;
	int nc = image.cols;

	Mat result(image.size(), CV_8U, Scalar(0));

	for (int i = 1; i < nr - 1; i++) {
		const uchar* prevRow = image.ptr<uchar>(i - 1);
		const uchar* currRow = image.ptr<uchar>(i);
		const uchar* nextRow = image.ptr<uchar>(i + 1);

		for (int j = 1; j < nc - 1; j++) {
			uchar resPix = 0;
			const uchar currPix = currRow[j];

			resPix |= (currRow[j - 1] >= currPix) << 7;
			resPix |= (nextRow[j - 1] >= currPix) << 6;
			resPix |= (nextRow[j] >= currPix) << 5;
			resPix |= (nextRow[j + 1] >= currPix) << 4;
			resPix |= (currRow[j + 1] >= currPix) << 3;
			resPix |= (prevRow[j + 1] >= currPix) << 2;
			resPix |= (prevRow[j] >= currPix) << 1;
			resPix |= (prevRow[j - 1] >= currPix);
			result.at<uchar>(i, j) = resPix;
		}
	}
	return result;
}


void ApanoramaReader::createMaterialLBPImage()
{
	int numCnt = 0;
	for (int i = 0; i < imagePath_MaterialImg.size(); i++)
	{
		TArray<Mat> arr;
		materialImgs.Add(arr);
		for (int j = 0; j < imagePath_MaterialImg[i].size(); j++)
		{
			//Load rgb image
			FString pathString = filePath + imagePath_MaterialImg[i][j];

			Mat img = imread(TCHAR_TO_UTF8(*pathString));

			if (img.empty())
				UE_LOG(SphericalFPS, Warning, TEXT("material file not found."));

			materialImgs[i].Add(img);
			numCnt++;
		}
	}
	UE_LOG(SphericalFPS, Warning, TEXT("MatImg Num : %d"), numCnt);
	for (int i = 0; i < materialImgs.Num(); i++)
	{
		TArray<Mat> arr;
		materialCSLBPImgs.Add(arr);
		for (int j = 0; j < materialImgs[i].Num(); j++)
		{
			Mat imgGray;
			cvtColor(materialImgs[i][j], imgGray, 6);

			Mat imgCSLBP;
			imgCSLBP = getCSLBPImage(imgGray);

			string nameStr = "material img" + to_string(i);

			if (isShowPanoImage)
				showCSLBPIamge(nameStr, imgCSLBP);

			materialCSLBPImgs[i].Add(imgCSLBP);
		}
	}
	for (int i = 0; i < materialCSLBPImgs.Num(); i++)
	{
		TArray<vector<float>> arr;
		materialHistogramNorm.Add(arr);
		for (int j = 0; j < materialCSLBPImgs[i].Num(); j++)
		{
			vector<float> matHist = getCSLBPHistogramNorm(materialCSLBPImgs[i][j]);
			materialHistogramNorm[i].Add(matHist);
		}
	}
}

//###############################
// File IO
//###############################
bool ApanoramaReader::loadFile(imageDatabase* imgData)
{
	FString pathString;

	isOpened = true;

	if (playMode == PlayMode::Video)
	{
		//Load rgb image
		pathString = filePath + imagePath_RGB;
		imgData->VCap_RGB = VideoCapture(TCHAR_TO_UTF8(*pathString));
		if (!imgData->VCap_RGB.isOpened())
		{
			isOpened = false;
		}
		else
		{
			//Adjust Width and Height of Video
			imgData->VCap_RGB.set(CAP_PROP_FRAME_WIDTH, panoramaWidth);
			imgData->VCap_RGB.set(CAP_PROP_FRAME_HEIGHT, panoramaHeight);
		}

		//Load depth image
		pathString = filePath + imagePath_Depth;
		imgData->VCap_Depth = VideoCapture(TCHAR_TO_UTF8(*pathString));
		if (!imgData->VCap_Depth.isOpened())
		{
			isOpened = false;
		}
		else
		{
			//Adjust Width and Height of Video
			imgData->VCap_Depth.set(CAP_PROP_FRAME_WIDTH, panoramaWidth);
			imgData->VCap_Depth.set(CAP_PROP_FRAME_HEIGHT, panoramaHeight);
		}
	}
	else
	{
		//Load rgb image
		pathString = filePath + imagePath_RGB;
		imgData->sourceImg_RGB = imread(TCHAR_TO_UTF8(*pathString));

		if (imgData->sourceImg_RGB.empty())
			isOpened = false;

		//Load depth image
		pathString = filePath + imagePath_Depth;
		imgData->sourceImg_Depth = imread(TCHAR_TO_UTF8(*pathString));

		if (imgData->sourceImg_Depth.empty())
			isOpened = false;
	}

	return isOpened;
}

//###############################
// Initialize
//###############################1
void ApanoramaReader::initImageDatabase(imageDatabase* imgData, int width, int height)
{
	Size size = Size((int)width / 4, (int)height / 2);
	imgData->sz = size;

	//Init Image
	imgData->TopImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
	imgData->BottomImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
	imgData->RearImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
	imgData->LeftImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
	imgData->FrontImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
	imgData->RightImg = Mat(Size(size), CV_8UC3, Scalar(0, 0, 0));
}
void ApanoramaReader::initTexture(Size size)
{
	//Init Texture
	TopTexture = UTexture2D::CreateTransient(size.width, size.height);
	TopTexture->UpdateResource();
	BottomTexture = UTexture2D::CreateTransient(size.width, size.height);
	BottomTexture->UpdateResource();
	RearTexture = UTexture2D::CreateTransient(size.width, size.height);
	RearTexture->UpdateResource();
	LeftTexture = UTexture2D::CreateTransient(size.width, size.height);
	LeftTexture->UpdateResource();
	FrontTexture = UTexture2D::CreateTransient(size.width, size.height);
	FrontTexture->UpdateResource();
	RightTexture = UTexture2D::CreateTransient(size.width, size.height);
	RightTexture->UpdateResource();
}

//###############################
// Texture Process
//###############################
void ApanoramaReader::updateTextureAll(imageDatabase* imgdata)
{
	//Update Texture
	updateTextureAtOneTime(imgdata->sz, &imgdata->TopImg, TopTexture);
	updateTextureAtOneTime(imgdata->sz, &imgdata->BottomImg, BottomTexture);
	updateTextureAtOneTime(imgdata->sz, &imgdata->RearImg, RearTexture);
	updateTextureAtOneTime(imgdata->sz, &imgdata->LeftImg, LeftTexture);
	updateTextureAtOneTime(imgdata->sz, &imgdata->FrontImg, FrontTexture);
	updateTextureAtOneTime(imgdata->sz, &imgdata->RightImg, RightTexture);
}
void ApanoramaReader::updateTextureAtOneTime(Size size, Mat* image, UTexture2D* texture)
{
	Data.Init(FColor(0, 0, 0, 255), size.width * size.height);
	if (image->data)
	{
		// Copy Mat data to Data array
		for (int y = 0; y < size.height; y++)
		{
			for (int x = 0; x < size.width; x++)
			{
				int i = x + (y * size.height);
				Data[i].B = image->data[i * 3 + 0];
				Data[i].G = image->data[i * 3 + 1];
				Data[i].R = image->data[i * 3 + 2];
			}
		}

		FTexture2DMipMap& Mip = texture->PlatformData->Mips[0];
		void* pData = Mip.BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(pData, Data.GetData(), Data.Num() * 4);
		Mip.BulkData.Unlock();
		texture->UpdateResource();
	}
}