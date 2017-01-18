#include <iostream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"


class ImageProcessor
{
public:
    ImageProcessor(int, double, std::string);
    ~ImageProcessor()=default;

    void gaussianBlur(cv::Mat);
    void sharpen(cv::Mat);

private:
    void saveImageToDisk();
    
private:
    cv::Mat dst;
    std::string img_name;
    std::vector<int> compression_params;
    int fsize;
    double sdev;
};


ImageProcessor::ImageProcessor(int sz = 3, double sd = 0.0 , std::string name = "0")
    : fsize{sz}, sdev{sd}, img_name{name} {}


void 
ImageProcessor::gaussianBlur(cv::Mat src) 
    //Blurs image by applying a gaussian filter with a default filter 
    //size of 31. The blurred image is named and saved to file.
{   
    int sz = this->fsize;
    double sd = this->sdev;

    cv::GaussianBlur(src, this->dst, cv::Size(sz, sz), sd, sd);
    this->saveImageToDisk();
}


void 
ImageProcessor::sharpen(cv::Mat src)
{
    int sz = this->fsize;
    double sd = this->sdev;
    cv::Mat tmp;

    cv::GaussianBlur(src, tmp, cv::Size(sz, sz), sd, sd);
    cv::addWeighted(src, 1.5, tmp, -0.5, 0, this->dst);
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
    
