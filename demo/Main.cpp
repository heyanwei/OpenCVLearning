#include "imageProc/HImage.h"

#include <memory>
#include <iostream>

int main(int argc, char const *argv[])
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

    img->Resize(0.5);
    img->Show();
    cv::waitKey(0);

    return 0;
}
