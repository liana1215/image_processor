#include <iostream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"


class ImageProcessor
{
public:
    ImageProcessor(const int, const double, const std::string);
    ~ImageProcessor()=default;

    int fsize;
    double sdev;

    void gaussianBlur(cv::Mat);

private:
    void saveImageToDisk();
    
private:
    cv::Mat temp;
    cv::Mat dst;
    std::string img_name;
    std::vector<int> compression_params;
};


ImageProcessor::ImageProcessor(const int sz, const double sdev, const std::string name)
{
    this->fsize = sz;       //set filter size
    this->sdev = sdev;      //set standard deviation x,y axis
    this->img_name = name;  //define output name
}


void 
ImageProcessor::gaussianBlur(cv::Mat src) 
{   
    int sz = this->fsize;
    double sd = this->sdev;

    cv::GaussianBlur(src, this->dst, cv::Size(sz, sz), sd, sd);
    this->saveImageToDisk();
}


void 
ImageProcessor::saveImageToDisk(void)
{
    this->compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    this->compression_params.push_back(9);

    try 
    {
        cv::imwrite(this->img_name, this->dst, this->compression_params);
    }
    catch (std::exception &ex) 
    {
        std::cerr << "Exception converting image to PNG format:" 
                  << ex.what()
                  << std::endl;
    }
}


int 
main(int argc, char** argv) 
{
    std::string img_name = argv[2];     //name of image output
    cv::Mat src;

    src = cv::imread(argv[1], 1);       //read in path to file

    if (argc != 3 || !src.data) 
    {
        std::cout << "No Image" << std::endl;
        return -1;
    }
        
    ImageProcessor ImgProc = ImageProcessor(31, 0.0, img_name);
    ImgProc.gaussianBlur(src);
                
    return 0;
}
    
