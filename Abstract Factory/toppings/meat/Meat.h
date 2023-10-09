#ifndef MEAT
#define MEAT

#include <string>

namespace abstractfactorytoppings::meat
{

	//TODO: Create Ham and Chicken or Weisswurst classes 
	//		Use separate header files in the same folder
	class Meat
	{
	public:
		virtual std::string toString() = 0;
	};

}


#endif	//#ifndef MEAT
