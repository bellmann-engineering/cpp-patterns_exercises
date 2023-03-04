#ifndef SLICEDPEPPERONI
#define SLICEDPEPPERONI

#include "Pepperoni.h"
#include <string>

namespace abstractfactorytoppings::pepperoni
{


	class SlicedPepperoni : public Pepperoni
	{

	public:
		std::string toString() override
		{
			return "Sliced Pepperoni";
		}
	};

}


#endif	//#ifndef SLICEDPEPPERONI
