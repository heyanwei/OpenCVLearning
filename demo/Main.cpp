#include "imageProc/HImage.h"
#include "imageProc/HMatrix.h"
#include "camera/HCamera.h"

#include <memory>
#include <iostream>

#include "utils/log/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

void RollbackHandle(const char *filename, std::size_t size) {}
void initlog()
{
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
                                       "%datetime|%level: %msg [%fbase %line]");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "/home/wilson/code/opencv/log/%datetime{%Y%M%d}.log");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "2097152");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::PerformanceTracking, "false");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");

    el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
    el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

    el::Helpers::installPreRollOutCallback(RollbackHandle);
}

int HExit()
{
    cv::waitKey(0);
    LOG(INFO) << "================program end================";
    return 0;
}

int main(int argc, char const *argv[])
{
    initlog();
    LOG(INFO) << "===================================";
    LOG(INFO) << "===========program start===========";

    if (argc < 3)
    {
        LOG(ERROR) << "Parameters are less than 3..." << el::base::consts::kPerformanceLoggerId;
        return HExit();
    }

    LOG(INFO) << "argc: " << argc << ", argv: " << argv[0] << " " << argv[1] << " " << argv[2];

    std::string pro = argv[1];
    std::string func = argv[2];

    if (pro == "image")
    {
        std::shared_ptr<image::HImage> img = std::make_shared<
            image::HImage>("smile", "../images/1.jpg");
        if (!img->LoadMat())
        {
            std::cout << "LoadMat failed" << std::endl;
            return HExit();
        }
        img->Show();
        cv::waitKey(0);
        if (argc < 3)
        {
            std::cout << "parameter error..." << std::endl;
            return HExit();
        }

        if (func == "resize")
        {
            //img->Resize(0.5,2);
            img->MResize(0.1, 0.1);
        }
        else if (func == "cut")
        {
            img->MCut(240, 240, 500, 500);
        }
        img->Show();
    }
    else if (pro == "matrix")
    {
        std::shared_ptr<image::HMatrix> mat = std::make_shared<image::HMatrix>();
    }
    else if (pro == "camera")
    {
        camera::HCamera came;
        came.LoadXml();
        came.Open();

        if (func == "show" || func == "s")
        {
            while (true)
            {
                came.Show();
                cv::waitKey(5);
            }
        }
        else if (func == "catch" || func == "c")
        {
            int n = 10;
            while (n)
            {
                if (came.SaveFace(std::to_string(n)))
                {
                    n--;
                }
                cv::waitKey(10);
            }
        }
    }

    return HExit();
}
