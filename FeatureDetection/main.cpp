#include "FeatureDetect.h"
#include <io.h>
#include <direct.h>
#include <iomanip>
enum FEATURE_TYPE{
	SIFT_FEATURE = 0,
	SURF_FEATURE = 1,
	ORB_FEATURE = 2
};

void getFiles( string path, vector<string>& files ) {
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  

    string p;

    if   ((hFile   =   _findfirst(p.assign(path).append("/*").c_str(),&fileinfo))   !=   -1)  {  

        do  {  
            //如果是目录,迭代之
            //如果不是,加入列表
            if   ((fileinfo.attrib   &   _A_SUBDIR)) {  
                if   (strcmp(fileinfo.name,".")   !=   0   &&   strcmp(fileinfo.name,"..")   !=   0)  
                    getFiles(   p.assign(path).append("/").append(fileinfo.name), files   );  
            }  else  {  
                files.push_back(   p.assign(path).append("/").append(fileinfo.name)  );
            }  
        }   while   (_findnext(   hFile,   &fileinfo   )   ==   0);  

        _findclose(hFile);  
    }
}

vector<string> getTifFiles(vector<string> files){
	vector<string> tifFiles;
	for (int i=0; i<files.size(); i++)
	{
		string path = files.at(i);
		int index = path.find('.');
		int length = path.length();
		string filetype = path.substr(index,length);
		if (filetype.compare("tif"))
		{
			tifFiles.push_back(path);
		}
	}
	return tifFiles;
}

/*****************************************************************************
    *  @brief    : setOutputImagePath 根据inputImagePath,type设置输出图片的路径
    *  @author   : Zhangle
    *  @date     : 2014/9/8 10:22
    *  @version  : ver 1.0
    *  @inparam  : inputImagePath 输入图片的路径
	*  @inparam  : type 特征点的类型
    *  @outparam : outputImagePath 输出图片的路径 
*****************************************************************************/
string setOutputImagePath(string inputImagePath, int type){
	string outputImagePath = "";
	int index = inputImagePath.find('.');
	outputImagePath = inputImagePath.substr(0,index);
	if (type == SIFT_FEATURE)
	{
		outputImagePath.append("_SIFT.TIF");
	} 
	else if(type == SURF_FEATURE)
	{
		outputImagePath.append("_SURF.TIF");
	} else {
		outputImagePath.append("_ORB.TIF");
	}
	return outputImagePath;
}

/*****************************************************************************
    *  @brief    : setOutputTxtPath
    *  @author   : Zhangle
    *  @date     : 2014/9/8 10:23
    *  @version  : ver 1.0
    *  @inparam  : inputImagePath 输入图片的路径
	*  @inparam  : type 特征点的类型
    *  @outparam : outputTxtPath 输出txt的路径 
*****************************************************************************/
string setOutputTxtPath(string inputImagePath, int type){
	string outputTxtPath = "";
	int index = inputImagePath.find('.');
	outputTxtPath = inputImagePath.substr(0,index);
	if (type == SIFT_FEATURE)
	{
		outputTxtPath.append("_SIFT.TXT");
	} 
	else if(type == SURF_FEATURE)
	{
		outputTxtPath.append("_SURF.TXT");
	} else {
		outputTxtPath.append("_ORB.TXT");
	}
	return outputTxtPath;
}



/*****************************************************************************
    *  @brief    : main 主函数
    *  @author   : Zhangle
    *  @date     : 2014/9/8 10:25
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
int main(){
	
	string outputImagePath = "";
	string outputTxtPath = "";
	string inputImagePath = "";

// 	vector<string> files;
// 	getFiles("F:/test",files);
	
	FeatureDetect *fd;
	cout<<"开始提取特征点"<<endl;

	fd = new FeatureDetect; //
	inputImagePath = "F:/test/TTC00405.TIF";//图片路径
	/*提取特征点*/
	outputImagePath = setOutputImagePath(inputImagePath, SIFT_FEATURE);			//设置输出图像的路径
	outputTxtPath = setOutputTxtPath(inputImagePath,SIFT_FEATURE);				//设置输出txt的路径
	fd->siftFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);		//提取SIFT特征点

	outputImagePath = setOutputImagePath(inputImagePath, SURF_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SURF_FEATURE);
	fd->surfFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);		//提取SURF特征点

	outputImagePath = setOutputImagePath(inputImagePath, ORB_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,ORB_FEATURE);
	fd->orbFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);		//提取ORB特征点

	fd = new FeatureDetect;
	inputImagePath = "F:/test/TTC00406.TIF";
	outputImagePath = setOutputImagePath(inputImagePath, SIFT_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SIFT_FEATURE);
	fd->siftFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, SURF_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SURF_FEATURE);
	fd->surfFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, ORB_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,ORB_FEATURE);
	fd->orbFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);

	fd = new FeatureDetect;
	inputImagePath = "F:/test/TTC00436.TIF";
	outputImagePath = setOutputImagePath(inputImagePath, SIFT_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SIFT_FEATURE);
	fd->siftFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, SURF_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SURF_FEATURE);
	fd->surfFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, ORB_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,ORB_FEATURE);
	fd->orbFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);

	fd = new FeatureDetect;
	inputImagePath = "F:/test/TTC00601.TIF";
	outputImagePath = setOutputImagePath(inputImagePath, SIFT_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SIFT_FEATURE);
	fd->siftFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, SURF_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,SURF_FEATURE);
	fd->surfFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);
	outputImagePath = setOutputImagePath(inputImagePath, ORB_FEATURE);
	outputTxtPath = setOutputTxtPath(inputImagePath,ORB_FEATURE);
	fd->orbFeatureDetect(inputImagePath, outputImagePath, outputTxtPath);

	cout<<"特征点提取结束.."<<endl;
}

