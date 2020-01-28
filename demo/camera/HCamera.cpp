#include "HCamera.h"

#include <stdio.h>
#include <iostream>
#include <string>

#include "utils/log/easylogging++.h"

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

bool HCamera::LoadXml()
{
    if (!_cascaClassifier.load("/home/wilson/software/opencv/data/haarcascades/haarcascade_frontalface_alt.xml"))
    {
        LOG(ERROR) << "load face model failed...";
        return false;
    }
    return true;
}

bool HCamera::Open()
{
    std::cout << "HCamera start to open ..." << std::endl;

    _capture.open(0);
    if (!_capture.isOpened())
    {
        std::cout << "HCamera open failed..." << std::endl;
        return false;
    }
    std::cout << "HCamera open success..." << std::endl;

    return true;
}

bool HCamera::Show()
{
    while (true)
    {
        cv::Mat frame;
        _capture >> frame;
        if (frame.empty())
        {
            std::cout << "HCamera frame is empty..." << std::endl;
            break;
        }
        cv::Mat tmpMat = frame.clone();
        cv::cvtColor(tmpMat, tmpMat, CV_BGR2GRAY);
        cv::equalizeHist(tmpMat, tmpMat); //直方图均衡化
        std::vector<cv::Rect> rect;
        //分类器在不同的人脸尺度空间上计算并将结果返回到rect矩形数组中
        _cascaClassifier.detectMultiScale(tmpMat, rect, 1.1, 3, 0, cv::Size(25, 25));

        for (size_t t = 0; t < rect.size(); t++)
        {
            cv::rectangle(frame, rect[static_cast<int>(t)], cv::Scalar(0, 0, 255), 2, 8, 0);
        }

        imshow("HCamera", frame);
        cv::waitKey(20);
    }
    return false;
}

bool HCamera::SaveFace()
{
    int num = 0;
    while (true)
    {
        cv::Mat frame;
        _capture >> frame;
        if (frame.empty())
        {
            std::cout << "HCamera frame is empty..." << std::endl;
            break;
        }
        cv::Mat tmpMat = frame.clone();
        cv::cvtColor(tmpMat, tmpMat, CV_BGR2GRAY);
        cv::equalizeHist(tmpMat, tmpMat); //直方图均衡化

        std::vector<cv::Rect> rect;
        _cascaClassifier.detectMultiScale(tmpMat, rect, 1.1, 3, 0, cv::Size(25, 25));
        if (rect.size() > 1)
        {
            std::cout << "HCamera has more faces..." << std::endl;
            continue;
        }

        cv::rectangle(frame, rect[static_cast<int>(0)], cv::Scalar(0, 0, 255), 2, 8, 0);

        std::string path = std::to_string(num) + ".png";
        if (!cv::imwrite(path, frame))
        {
            std::cout << "HCamera write failed..." << std::endl;
            continue;
        }
        num++;

        if (num > 9)
        {
            break;
        }

        imshow("HCamera", frame);
        cv::waitKey(20);
    }
    return false;
}

} // namespace camera