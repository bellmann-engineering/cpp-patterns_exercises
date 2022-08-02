#ifndef PEPPERONIPIZZA
#define PEPPERONIPIZZA

#include "../toppingfactory/PizzaToppingFactory.h"
#include "Pizza.h"
#include <iostream>

namespace abstractfactorypizza
{

	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	class PepperoniPizza : public Pizza
	{
	public:
		PizzaToppingFactory* ingredientFactory;

		virtual ~PepperoniPizza()
		{
			delete ingredientFactory;
		}

		PepperoniPizza(PizzaToppingFactory* ingredientFactory)
		{
			this->ingredientFactory = ingredientFactory;
		}

		void prepare() override
		{
			std::cout << "Preparing " << name << std::endl;
			dough = ingredientFactory->createDough();
			sauce = ingredientFactory->createSauce();
			cheese = ingredientFactory->createCheese();
			veggies = ingredientFactory->createVeggies();
			pepperoni = ingredientFactory->createPepperoni();
		}
	};

}


#endif	//#ifndef PEPPERONIPIZZA
