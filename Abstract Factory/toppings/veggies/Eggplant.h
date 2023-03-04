#ifndef EGGPLANT
#define EGGPLANT

#include "Veggies.h"
#include <string>

namespace abstractfactorytoppings::veggies
{


	class Eggplant : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Eggplant";
		}
	};

}


#endif	//#ifndef EGGPLANT
