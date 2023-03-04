#ifndef BLACKOLIVES
#define BLACKOLIVES

#include "Veggies.h"
#include <string>

namespace abstractfactorytoppings::veggies
{


	class BlackOlives : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Black Olives";
		}
	};

}


#endif	//#ifndef BLACKOLIVES
