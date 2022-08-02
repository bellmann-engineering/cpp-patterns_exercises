#ifndef VEGGIEPIZZA
#define VEGGIEPIZZA

#include "../toppingfactory/PizzaToppingFactory.h"
#include "Pizza.h"
#include <iostream>

namespace abstractfactorypizza
{

	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	class VeggiePizza : public Pizza
	{
	public:
		PizzaToppingFactory* ingredientFactory;

		virtual ~VeggiePizza()
		{
			delete ingredientFactory;
		}

		VeggiePizza(PizzaToppingFactory* ingredientFactory)
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
		}
	};

}


#endif	//#ifndef VEGGIEPIZZA
