#ifndef THICKCRUSTDOUGH
#define THICKCRUSTDOUGH

#include "Dough.h"
#include <string>

namespace abstractfactorytoppings::dough
{


	class ThickCrustDough : public Dough
	{
	public:
		std::string toString() override
		{
			return "ThickCrust style extra thick crust dough";
		}
	};

}


#endif	//#ifndef THICKCRUSTDOUGH
