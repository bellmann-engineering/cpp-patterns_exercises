#ifndef FROZENCLAMS
#define FROZENCLAMS

#include "Clams.h"
#include <string>

namespace abstractfactorytoppings::clams
{


	class FrozenClams : public Clams
	{

	public:
		std::string toString() override
		{
			return "Frozen Clams from Chesapeake Bay";
		}
	};

}


#endif	//#ifndef FROZENCLAMS
