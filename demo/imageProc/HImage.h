#pragma once

#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace image
{
class HImage
{
private:
    std::string _name;
    std::string _image;
    cv::Mat _mat;

public:
    HImage(std::string name, std::string image);
    ~HImage();

    bool LoadMat();
    bool Resize(double x_scale, double y_scale);
    bool MResize(double x_scale, double y_scale);

    bool Show();
};

} // namespace image