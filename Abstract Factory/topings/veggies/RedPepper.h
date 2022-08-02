#ifndef REDPEPPER
#define REDPEPPER

#include "Veggies.h"
#include <string>

namespace abstractfactorytopings::veggies
{

	class RedPepper : public Veggies
	{

	public:
		std::string toString() override
		{
			return "Red Pepper";
		}
	};

}


#endif	//#ifndef REDPEPPER
