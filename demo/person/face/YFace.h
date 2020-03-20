#pragma once

#include "../interface/YPerson.h"

namespace person
{
	class YFace : public YPerson
	{
	public:
		virtual bool Init() override;

		virtual bool Train() override;

	};

}

