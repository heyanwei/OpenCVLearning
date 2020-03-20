#pragma once

#include "../interface/YPerson.h"

namespace person
{
	class YBody : public YPerson
	{
	public:
		virtual bool Init() override;

		virtual bool Train() override;
	};
}


