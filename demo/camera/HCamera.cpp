#include "HCamera.h"

#include <stdio.h>
#include <iostream>

namespace camera
{
HCamera::HCamera()
{
    std::cout << "HCamera init..." << std::endl;
}

HCamera::~HCamera()
{
    std::cout << "HCamera end..." << std::endl;
}

bool HCamera::Open()
{
    std::cout << "HCamera start to open ..." << std::endl;
    cv::VideoCapture capture;
    capture.open(0);
    if (!capture.isOpened())
    {
        std::cout << "HCamera open failed..." << std::endl;
        return false;
    }
    std::cout << "HCamera open success..." << std::endl;
  
    while (true)
    {      
        cv::Mat frame;
        capture >> frame;
        if (frame.empty())
        {
            std::cout << "HCamera frame is empty..." << std::endl;
            break;
        }
        imshow("HCamera", frame);
        cv::waitKey(30);
    }

    return true;
}

bool HCamera::Show()
{
    return false;
}

} // namespace camera