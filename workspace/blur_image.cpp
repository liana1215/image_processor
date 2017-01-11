#include <iostream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"

 

int 
main(int argc, char** argv) 
{
    std::vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    
    //name of image output
    std::string img_name = argv[2];

    cv::Mat src, dst;

    //read in path to file
    src = cv::imread(argv[1], 1);

    if (argc != 3 || !src.data) 
    {
        std::cout << "No Image" << std::endl;
        return -1;
    }
        
    cv::GaussianBlur(src, dst, cv::Size(31,31),0,0);

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
                 
    return 0;
}
    
