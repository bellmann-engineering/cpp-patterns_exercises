#ifndef CHEESEPIZZA
#define CHEESEPIZZA

#include "../toppingfactory/PizzaToppingFactory.h"
#include "Pizza.h"
#include <iostream>

namespace abstractfactorypizza
{

	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	class CheesePizza : public Pizza
	{
	public:
		PizzaToppingFactory* ingredientFactory;

		virtual ~CheesePizza()
		{
			delete ingredientFactory;
		}

		CheesePizza(PizzaToppingFactory* ingredientFactory)
		{
			this->ingredientFactory = ingredientFactory;
		}

		void prepare() override
		{
			std::cout << "Preparing " << name << std::endl;
			dough = ingredientFactory->createDough();
			sauce = ingredientFactory->createSauce();
			cheese = ingredientFactory->createCheese();
		}
	};

}


#endif	//#ifndef CHEESEPIZZA
