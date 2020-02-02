#include "HCamera.h"

#include <stdio.h>
#include <iostream>
#include <string>

#include "utils/log/easylogging++.h"

namespace camera
{
HCamera::HCamera()
{
    LOG(INFO) << "HCamera init..." << el::base::consts::kPerformanceLoggerId;
}

HCamera::~HCamera()
{
    LOG(INFO) << "HCamera end...";
}

bool HCamera::LoadXml()
{
    if (!_faceCascaClassifier.load("/home/wilson/software/opencv/data/haarcascades/haarcascade_frontalface_alt.xml"))
    {
        LOG(ERROR) << "load face model failed...";
        return false;
    }
    return true;
}

bool HCamera::Open()
{
    LOG(INFO) << "HCamera start to open ...";

    _capture.open(0);
    if (!_capture.isOpened())
    {
        LOG(INFO) << "HCamera start failed ...";
        return false;
    }
    LOG(INFO) << "HCamera start succeeded ...";

    return true;
}

bool HCamera::Show()
{
    cv::Mat frame;
    _capture >> frame;
    if (frame.empty())
    {
        LOG(ERROR) << "HCamera frame is empty...";
        return false;
    }
    imshow("HCamera", frame);

    return true;
}

bool HCamera::SaveFace(std::string name)
{
    try
    {
        cv::Mat frame;
        _capture >> frame;
        if (frame.empty())
        {
            LOG(ERROR) << "HCamera frame is empty...";
            return false;
        }
        cv::Mat tmpMat = frame;
        cv::cvtColor(tmpMat, tmpMat, CV_BGR2GRAY);
        cv::equalizeHist(tmpMat, tmpMat); //直方图均衡化

        std::vector<cv::Rect> rect;
        _faceCascaClassifier.detectMultiScale(tmpMat, rect, 1.1, 3, 0, cv::Size(25, 25));
        if (rect.size() != 1)
        {
            LOG(ERROR) << "HCamera catch not 1 face..." << rect.size();
            imshow("HCamera", frame);
            return false;
        }

        LOG(INFO)<<"HCamera catch one face";

        cv::rectangle(frame, rect[0], cv::Scalar(0, 0, 255), 2, 8, 0);

        std::string path = "/home/wilson/code/img/hyw/" + name + ".png";
        if (!cv::imwrite(path, frame))
        {
            LOG(ERROR) << "HCamera write failed...";
            return false;
        }
        imshow("HCamera", frame);

        return true;
    }
    catch (const std::exception &e)
    {
        LOG(ERROR) << e.what();
    }
    return false;
}

} // namespace camera