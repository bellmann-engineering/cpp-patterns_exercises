#ifndef CLAMPIZZA
#define CLAMPIZZA

#include "../toppingfactory/PizzaToppingFactory.h"
#include "Pizza.h"
#include <iostream>

namespace abstractfactorypizza
{

	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	class ClamPizza : public Pizza
	{
	public:
		PizzaToppingFactory* ingredientFactory;

		virtual ~ClamPizza()
		{
			delete ingredientFactory;
		}

		ClamPizza(PizzaToppingFactory* ingredientFactory)
		{
			this->ingredientFactory = ingredientFactory;
		}

		void prepare() override
		{
			std::cout << "Preparing " << name << std::endl;
			dough = ingredientFactory->createDough();
			sauce = ingredientFactory->createSauce();
			cheese = ingredientFactory->createCheese();
			clam = ingredientFactory->createClam();
		}
	};

}


#endif	//#ifndef CLAMPIZZA
