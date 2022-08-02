#ifndef MEAT
#define MEAT

#include <string>

namespace abstractfactorytoppings::meat
{

	//TODO: Create Ham, Chicken or Weisswurst classes
	class Meat
	{
	public:
		virtual std::string toString() = 0;
	};

}


#endif	//#ifndef MEAT
