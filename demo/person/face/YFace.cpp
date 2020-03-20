#include "YFace.h"

#include "easylogging++.h"

namespace person
{
	bool YFace::Init()
	{
		return LoadModel("D:\\img\\dataset\\haarcascades\\haarcascade_frontalface_alt.xml");
	}

	bool YFace::Train()
	{

        return true;
	}
}
