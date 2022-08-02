#ifndef GARLIC
#define GARLIC

#include "Veggies.h"
#include <string>

namespace abstractfactorytopings::veggies
{


	class Garlic : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Garlic";
		}
	};

}


#endif	//#ifndef GARLIC
