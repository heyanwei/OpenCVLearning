#include "DahuaCamera.h"

#include "easylogging++.h"

namespace camera
{
	bool DahuaCamera::Open(std::string ip, std::string user, std::string password)
	{
		std::string url = "rtsp://" + user + ":" + password + "@" + ip + "/cam/realmonitor?channel=1&subtype=1";
		LOG(INFO) << "Open url: " << url;
		if (!_capture.open(url))
		{
			LOG(INFO) << "DahuaCamera open failed...";
			return false;
		}
		return true;
	}
}
