#include "imageProc/HImage.h"
#include "imageProc/HMatrix.h"
#include "camera/HCamera.h"

#include <memory>
#include <iostream>

#include "utils/log/easylogging++.h"

INITIALIZE_EASYLOGGINGPP


void RollbackHandle(const char* filename, std::size_t size) {}
void initlog()
{
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
                                       "%datetime|%level: %msg [%fbase %line]");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, "Log\\_%datetime{%Y%M%d}.log");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "2097152");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::PerformanceTracking, "false");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");

    el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
    el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

    el::Helpers::installPreRollOutCallback(RollbackHandle);
}

void note()
{
    std::cout << std::endl;
    std::cout << "=============Help=============" << std::endl;
    std::cout << "./demo image resize" << std::endl;
    std::cout << "./demo camera show" << std::endl;
    std::cout << "./demo matrix show" << std::endl;
    std::cout << "==============================" << std::endl;
}

int main(int argc, char const *argv[])
{
    initlog();

    if (argc < 3)
    {
        std::cout << "parameter error..."<< el::base::consts::kPerformanceLoggerId << std::endl;
        note();
        return -1;
    }

    LOG(INFO)<<"argc: "<<argc<<", argv: "<<argv[0]<<" "<<argv[1]<<" "<<argv[2];

    std::string pro = argv[1];

    if (pro == "image")
    {
        std::shared_ptr<image::HImage> img = std::make_shared<
            image::HImage>("smile", "../images/1.jpg");
        if (!img->LoadMat())
        {
            std::cout << "LoadMat failed" << std::endl;
            return 0;
        }
        img->Show();
        cv::waitKey(0);
        if (argc < 3)
        {
            std::cout << "parameter error..." << std::endl;
            note();
            return -1;
        }
        std::string func = argv[2];
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
        cv::waitKey(0);
    }
    else if (pro == "matrix")
    {
        std::shared_ptr<image::HMatrix> mat = std::make_shared<image::HMatrix>();
    }
    else if (pro == "camera")
    {
        camera::HCamera came;
        came.Open();
    }

    return 0;
}
