#pragma once
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <fstream>
#include <iostream>
using namespace std;
using namespace cv;
class FeatureDetect
{
public:
	FeatureDetect(void);
	~FeatureDetect(void);
	void siftFeatureDetect(string inputImageName, string outputImageName,string outputTxtName);
	void surfFeatureDetect(string inputImageName, string outputImageName,string outputTxtName);
	void orbFeatureDetect(string inputImageName, string outputImageName,string outputTxtName);
};

