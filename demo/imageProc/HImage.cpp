#include "HImage.h"

#include <stdio.h>
#include <iostream>

namespace image
{
HImage::HImage(std::string name, std::string image)
{
    _name = name;
    _image = image;

    std::cout << "HImage init..."<<_name<<" - " << _image << std::endl;
}

HImage::~HImage()
{
    std::cout << "HImage end..." <<_name<<" - " << _image << std::endl;
}

bool HImage::LoadMat()
{
    _mat = cv::imread(_image);
    if (!_mat.data)
    {
        std::cout << "no image data" << std::endl;
        return false;
    }

    std::cout << "image: " << _mat.rows << ", " << _mat.cols << std::endl;
    return true;
}

bool HImage::Resize(double scale)
{
    std::cout<<"before resize: "<<_mat.rows<<", "<<_mat.cols<<std::endl;
    cv::resize(_mat, _mat, cv::Size(_mat.rows*scale, _mat.cols*scale));
    std::cout<<"after resize: "<<_mat.rows<<", "<<_mat.cols<<std::endl;

    return true;
}

bool HImage::Show()
{
    cv::imshow(_name, _mat);
    return true;
}

} // namespace image