#ifndef PIZZASTORE
#define PIZZASTORE

#include "../pizza/Pizza.h"
#include <string>
#include <iostream>

namespace abstractfactorypizzastore
{

	using Pizza = abstractfactorypizza::Pizza;

	class PizzaStore
	{
		
	protected:
		virtual Pizza* createPizza(const std::string& item) = 0;

	public:
		virtual Pizza* orderPizza(const std::string& type)
		{
			Pizza* pizza = createPizza(type);	
			if(pizza != nullptr)
			{
				std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
				pizza->prepare();
				pizza->bake();
				pizza->cut();
				pizza->box();
			}
			
			return pizza;
		}
	};

}


#endif	//#ifndef PIZZASTORE
