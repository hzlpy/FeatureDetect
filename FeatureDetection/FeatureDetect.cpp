#include "FeatureDetect.h"


FeatureDetect::FeatureDetect(void)
{
}


FeatureDetect::~FeatureDetect(void)
{
}
/*****************************************************************************
    *  @brief    : siftFeatureDetect
    *  @author   : Zhangle
    *  @date     : 2014/9/8 11:18
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void FeatureDetect::siftFeatureDetect(string inputImageName, string outputImageName,string outputTxtName){
	Mat image = imread(inputImageName);
	Mat descriptors;
	vector<KeyPoint> keypoints;
	SIFT sift;
	time_t beginTime = time(NULL);
	sift.detect(image,keypoints);
	time_t endTime = time(NULL);
	time_t runTime = endTime - beginTime;
	drawKeypoints(image,keypoints,image,Scalar(0,255,0));
	imwrite(outputImageName,image);
	ofstream outTxt(outputTxtName);
	outTxt << "SIFT" << endl;
	outTxt << "Ӱ��ߴ�:" << image.cols<<" * "<<image.rows<<endl;
	outTxt << "��������Ŀ��" << keypoints.size() <<"��"<< endl;
	outTxt << "��ȡ������ķ�ʱ�䣺" << runTime << "s"<< endl;
	outTxt << "Ĭ�ϲ�������" << endl;
	outTxt.close();
}

/*****************************************************************************
    *  @brief    : surfFeatureDetect
    *  @author   : Zhangle
    *  @date     : 2014/9/8 11:18
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void FeatureDetect::surfFeatureDetect(string inputImageName, string outputImageName,string outputTxtName){
	Mat image = imread(inputImageName);
	Mat descriptors;
	vector<KeyPoint> keypoints;
	SURF surf;
	time_t beginTime = time(NULL);
	surf.detect(image,keypoints);
	time_t endTime = time(NULL);
	time_t runTime = endTime - beginTime;
	drawKeypoints(image,keypoints,image,Scalar(255,0,0));
	imwrite(outputImageName,image);
	ofstream outTxt(outputTxtName);
	outTxt << "SURF" << endl;
	outTxt << "Ӱ��ߴ�:" << image.cols<<" * "<<image.rows<<endl;
	outTxt << "��������Ŀ��" << keypoints.size() <<"��"<< endl;
	outTxt << "��ȡ������ķ�ʱ�䣺" << runTime << "s"<< endl;
	outTxt << "Ĭ�ϲ�������" << endl;
	outTxt.close();
}

/*****************************************************************************
    *  @brief    : orbFeatureDetect
    *  @author   : Zhangle
    *  @date     : 2014/9/8 11:17
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void FeatureDetect::orbFeatureDetect(string inputImageName, string outputImageName,string outputTxtName){
	Mat image = imread(inputImageName);
	Mat descriptors;
	vector<KeyPoint> keypoints;
	ORB orb;
	time_t beginTime = time(NULL);
	orb.detect(image,keypoints);
	time_t endTime = time(NULL);
	time_t runTime = endTime - beginTime;
	drawKeypoints(image,keypoints,image,Scalar(255,255,255));
	imwrite(outputImageName,image);
	ofstream outTxt(outputTxtName);
	outTxt << "ORB" << endl;
	outTxt << "Ӱ��ߴ�:" << image.cols<<" * "<<image.rows<<endl;
	outTxt << "��������Ŀ��" << keypoints.size() <<"��"<< endl;
	outTxt << "��ȡ������ķ�ʱ�䣺" << runTime << "s"<< endl;
	outTxt << "Ĭ�ϲ�������" << endl;
	outTxt.close();
}