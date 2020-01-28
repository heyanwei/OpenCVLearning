#pragma once

#include <string>

#include <opencv2/opencv.hpp>

namespace camera
{
class HCamera
{

public:
    HCamera();
    ~HCamera();

    bool LoadXml();
    bool Open();
    bool Show();
    bool SaveFace();

private:
    cv::VideoCapture _capture;
    cv::CascadeClassifier _cascaClassifier;
};

} // namespace camera