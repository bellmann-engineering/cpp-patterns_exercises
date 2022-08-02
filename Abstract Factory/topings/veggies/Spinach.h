#ifndef SPINACH
#define SPINACH

#include "Veggies.h"
#include <string>

namespace abstractfactorytopings::veggies
{

	class Spinach : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Spinach";
		}
	};

}


#endif	//#ifndef SPINACH
