#ifndef FRESHCLAMS
#define FRESHCLAMS

#include "Clams.h"
#include <string>

namespace abstractfactorytoppings::clams
{


	class FreshClams : public Clams
	{

	public:
		std::string toString() override
		{
			return "Fresh Clams from Long Island Sound";
		}
	};

}


#endif	//#ifndef FRESHCLAMS
