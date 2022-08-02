#ifndef REGGIANOCHEESE
#define REGGIANOCHEESE

#include "Cheese.h"
#include <string>

namespace abstractfactorytoppings::cheese
{


	class ReggianoCheese : public Cheese
	{

	public:
		std::string toString() override
		{
			return "Reggiano Cheese";
		}
	};

}


#endif	//#ifndef REGGIANOCHEESE
