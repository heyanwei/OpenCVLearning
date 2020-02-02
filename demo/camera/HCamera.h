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
    bool SaveFace(std::string name);
    bool Predict();

private:
    cv::VideoCapture _capture;
    cv::CascadeClassifier _faceCascaClassifier;
};

} // namespace camera