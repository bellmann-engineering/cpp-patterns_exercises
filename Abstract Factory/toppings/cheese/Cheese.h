#ifndef CHEESE
#define CHEESE

#include <string>

namespace abstractfactorytoppings::cheese
{

	class Cheese
	{
	public:
		virtual std::string toString() = 0;
	};

}


#endif	//#ifndef CHEESE
