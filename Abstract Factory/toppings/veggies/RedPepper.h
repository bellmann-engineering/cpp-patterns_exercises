#ifndef REDPEPPER
#define REDPEPPER

#include "Veggies.h"
#include <string>

namespace abstractfactorytoppings::veggies
{

	class RedPepper : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Red Pepper";
		}
	};

}


#endif	//#ifndef REDPEPPER
