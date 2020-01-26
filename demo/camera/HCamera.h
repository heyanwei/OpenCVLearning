#pragma once

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace camera
{
class HCamera
{

public:
    HCamera();
    ~HCamera();

    bool Open();
    bool Show();

    
};

} // namespace camera