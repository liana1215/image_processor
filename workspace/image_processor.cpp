#include "ImageProcessor.hpp"


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
    
