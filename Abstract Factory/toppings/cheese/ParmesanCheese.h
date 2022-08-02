#ifndef PARMESANCHEESE
#define PARMESANCHEESE

#include "Cheese.h"
#include <string>

namespace abstractfactorytoppings::cheese
{


	class ParmesanCheese : public Cheese
	{

	public:
		std::string toString() override
		{
			return "Shredded Parmesan";
		}
	};

}


#endif	//#ifndef PARMESANCHEESE
