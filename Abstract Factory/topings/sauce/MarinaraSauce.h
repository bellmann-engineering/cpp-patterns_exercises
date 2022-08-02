#ifndef MARINARASAUCE
#define MARINARASAUCE

#include "Sauce.h"
#include <string>

namespace abstractfactorytopings::sauce
{


	class MarinaraSauce : public Sauce
	{
	public:
		std::string toString() override
		{
			return "Marinara Sauce";
		}
	};

}


#endif	//#ifndef MARINARASAUCE
