#ifndef THINCRUSTDOUGH
#define THINCRUSTDOUGH

#include "Dough.h"
#include <string>

namespace abstractfactorytoppings::dough
{


	class ThinCrustDough : public Dough
	{
	public:
		std::string toString() override
		{
			return "Thin Crust Dough";
		}
	};

}


#endif	//#ifndef THINCRUSTDOUGH
