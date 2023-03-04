#ifndef SPINACH
#define SPINACH

#include "Veggies.h"
#include <string>

namespace abstractfactorytoppings::veggies
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
