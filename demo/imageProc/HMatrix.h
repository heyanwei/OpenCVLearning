#pragma once

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace image
{
class HMatrix
{
private:
    cv::Mat _mat;

public:
    HMatrix();
    ~HMatrix();

    
};

} // namespace image