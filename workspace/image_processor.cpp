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
    int fsz;    //filter size
    double fsd; //filter std deviation
};


ImageProcessor::ImageProcessor(int sz = 3, double sd = 0.0 , std::string name = "0")
    : fsz{sz}, fsd{sd}, img_name{name} {}


void 
ImageProcessor::gaussianBlur(cv::Mat src) 
    //Blurs image by applying a gaussian filter with a default filter 
    //size of 31. The blurred image is named and saved to file.
{   
    cv::GaussianBlur(src, dst, cv::Size(fsz, fsz), fsd, fsd);
    saveImageToDisk();
}


void 
ImageProcessor::sharpen(cv::Mat src)
{
    cv::Mat tmp;

    cv::GaussianBlur(src, tmp, cv::Size(fsz, fsz), fsd, fsd);
    cv::addWeighted(src, 1.5, tmp, -0.5, 0, dst);
    saveImageToDisk();
}


void 
ImageProcessor::saveImageToDisk(void)
{
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    try 
    {
        cv::imwrite(img_name, dst, compression_params);
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
    
