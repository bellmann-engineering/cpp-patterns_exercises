#ifndef ONION
#define ONION

#include "Veggies.h"
#include <string>

namespace abstractfactorytoppings::veggies
{

	class Onion : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Onion";
		}
	};

}


#endif	//#ifndef ONION
