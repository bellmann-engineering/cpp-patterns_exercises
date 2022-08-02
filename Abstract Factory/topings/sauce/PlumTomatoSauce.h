#ifndef PLUMTOMATOSAUCE
#define PLUMTOMATOSAUCE

#include "Sauce.h"
#include <string>

namespace abstractfactorytopings::sauce
{


	class PlumTomatoSauce : public Sauce
	{
	public:
		std::string toString() override
		{
			return "Tomato sauce with plum tomatoes";
		}
	};

}


#endif	//#ifndef PLUMTOMATOSAUCE
