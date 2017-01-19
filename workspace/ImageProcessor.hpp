#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include <iostream>   
#include <vector>       
#include "opencv2/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp"  

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

#endif

   
