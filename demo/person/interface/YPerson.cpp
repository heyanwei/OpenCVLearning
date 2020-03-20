#include "YPerson.h"

#include "easylogging++.h"

namespace person
{
	bool YPerson::LoadModel(std::string modelPath)
	{
		if (!_objectCascaClassifier.load(modelPath))
		{
			LOG(ERROR) << "load model failed...";
			return false;
		}
		return true;
	}
	bool YPerson::HasObject(cv::Mat mat, cv::Mat& retMat, std::vector<cv::Mat>& objects)
	{
        try
        {
            if (mat.empty())
            {
                LOG(ERROR) << "mat is empty...";
                return false;
            }
            cv::Mat tmpMat = mat;
            cv::cvtColor(tmpMat, tmpMat, CV_BGR2GRAY);
            cv::equalizeHist(tmpMat, tmpMat);

            std::vector<cv::Rect> rect;
            _objectCascaClassifier.detectMultiScale(tmpMat, rect, 1.1, 3, 0, cv::Size(50, 50));

            for (int i = 0; i < int(rect.size()); i++)
            {
                cv::Rect roi = rect[i];

                cv::rectangle(mat, roi, cv::Scalar(0, 0, 255), 2, 8, 0);

                cv::Mat objMat = mat(roi);
                objects.push_back(objMat);
            }
            retMat = mat;

            return true;
        }
        catch (const std::exception & e)
        {
            LOG(ERROR) << e.what();
        }
        return false;
	}
}

