#include "ImageProcessor.hpp"


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
    //Sharpens the image by applying the Unsharp mask method.
    cv::Mat tmp;

    cv::GaussianBlur(src, tmp, cv::Size(fsz, fsz), fsd, fsd);
    cv::addWeighted(src, 1.5, tmp, -0.5, 0, dst);
    saveImageToDisk();
}


void 
ImageProcessor::saveImageToDisk(void)
{
    //Writes image file to specified directory, with assumption
    //the image is a png file.
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
