#include "HImage.h"

#include <stdio.h>
#include <iostream>

namespace image
{
HImage::HImage(std::string name, std::string image)
{
    _name = name;
    _image = image;

    std::cout << "HImage init..." << _name << " - " << _image << std::endl;
}

HImage::~HImage()
{
    std::cout << "HImage end..." << _name << " - " << _image << std::endl;
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

bool HImage::Resize(double x_scale, double y_scale)
{
    // 最基本的做法
    std::cout << "before resize: " << _mat.rows << ", " << _mat.cols << std::endl;
    cv::resize(_mat, _mat, cv::Size(_mat.rows * x_scale, _mat.cols * y_scale));
    std::cout << "after resize: " << _mat.rows << ", " << _mat.cols << std::endl;

    return true;
}

bool HImage::MResize1(double x_scale, double y_scale)
{
    //最近邻域插值法
    int sourceRows = _mat.rows;        //原来的行数
    int sourceCols = _mat.cols;        //原来的列数
    int newRows = _mat.rows * x_scale; //新的行数
    int newCols = _mat.cols * y_scale; //新的列数

    std::cout << "sourceRows: " << sourceRows << ", sourceCols: " << sourceCols
              << ", newRows: " << newRows << ", newCols: " << newCols << std::endl;

    //初始化矩阵，并把颜色（0，0，0）赋值给给个矩阵的每个元素
    cv::Mat tmpMat(newRows, newCols, CV_8UC3, cv::Scalar(0, 0, 0));
    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newCols; j++)
        {
            // sourceI/i = sourceRows/newRows，但如果newRows大于sourceRows，会一直是0，因此需要乘1.0变成浮点型
            int iSource = i * (sourceRows * 1.0 / newRows);
            int jSource = j * (sourceCols * 1.0 / newCols);

            tmpMat.at<cv::Vec3b>(i, j) = _mat.at<cv::Vec3b>(iSource, jSource);
        }
    }

    _mat = tmpMat;

    return true;
}


bool HImage::MResize2(double x_scale, double y_scale)
{
    //双线性插值
    //A1 = 20% 上+80%下 A2
    //B1 = 30% 左+70%右 B2
    //最终点 = A1 30% + A2 70%
    //最终点 = B1 20% + B2 80%
    int sourceRows = _mat.rows;        //原来的行数
    int sourceCols = _mat.cols;        //原来的列数
    int newRows = _mat.rows * x_scale; //新的行数
    int newCols = _mat.cols * y_scale; //新的列数

    std::cout << "sourceRows: " << sourceRows << ", sourceCols: " << sourceCols
              << ", newRows: " << newRows << ", newCols: " << newCols << std::endl;

    //初始化矩阵，并把颜色（0，0，0）赋值给给个矩阵的每个元素
    cv::Mat tmpMat(newRows, newCols, CV_8UC3, cv::Scalar(0, 0, 0));
    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newCols; j++)
        {
            // sourceI/i = sourceRows/newRows，但如果newRows大于sourceRows，会一直是0，因此需要乘1.0变成浮点型
            int iSource = i * (sourceRows * 1.0 / newRows);
            int jSource = j * (sourceCols * 1.0 / newCols);

            tmpMat.at<cv::Vec3b>(i, j) = _mat.at<cv::Vec3b>(iSource, jSource);
        }
    }

    _mat = tmpMat;

    return true;
}

bool HImage::Show()
{
    cv::imshow(_name, _mat);
    return true;
}

} // namespace image