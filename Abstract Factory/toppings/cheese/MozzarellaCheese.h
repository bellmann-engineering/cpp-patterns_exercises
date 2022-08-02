#ifndef MOZZARELLACHEESE
#define MOZZARELLACHEESE

#include "Cheese.h"
#include <string>

namespace abstractfactorytoppings::cheese
{


	class MozzarellaCheese : public Cheese
	{

	public:
		std::string toString() override
		{
			return "Shredded Mozzarella";
		}
	};

}


#endif	//#ifndef MOZZARELLACHEESE
