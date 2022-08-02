#ifndef MUSHROOM
#define MUSHROOM

#include "Veggies.h"
#include <string>

namespace abstractfactorytopings::veggies
{

	class Mushroom : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Mushrooms";
		}
	};

}


#endif	//#ifndef MUSHROOM
