#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/face.hpp>

namespace person
{
	class YPerson
	{
	public:
		virtual bool Init() = 0;
		virtual bool Train() = 0;

		bool LoadModel(std::string modelPath);

		bool HasObject(cv::Mat mat, cv::Mat& retMat, std::vector<cv::Mat>& objects);

	protected:
		cv::CascadeClassifier _objectCascaClassifier;
	};
}


