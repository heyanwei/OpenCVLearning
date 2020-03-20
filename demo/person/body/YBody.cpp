#include "YBody.h"

#include "easylogging++.h"

namespace person
{
	bool YBody::Init()
	{
		return LoadModel("D:\\img\\dataset\\haarcascades\\haarcascade_eye.xml");
	}
	bool YBody::Train()
	{
		return false;
	}
}