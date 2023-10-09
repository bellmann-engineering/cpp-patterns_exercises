#ifndef NYPIZZASTORE
#define NYPIZZASTORE

#include "../pizza/CheesePizza.h"
#include "../pizza/ClamPizza.h"
#include "../pizza/PepperoniPizza.h"
#include "../pizza/Pizza.h"
#include "../pizza/VeggiePizza.h"
//TODO include head for MeatPizza

#include "../toppingfactory/NYPizzaToppingFactory.h"
#include "../toppingfactory/PizzaToppingFactory.h"
#include "PizzaStore.h"
#include <string>

namespace abstractfactorypizzastore
{

	using CheesePizza = abstractfactorypizza::CheesePizza;
	using ClamPizza = abstractfactorypizza::ClamPizza;
	using PepperoniPizza = abstractfactorypizza::PepperoniPizza;
	using Pizza = abstractfactorypizza::Pizza;
	using VeggiePizza = abstractfactorypizza::VeggiePizza;
	//TODO: include MeatPizza
	
	using NYPizzaToppingFactory = abstractfactorytoppingfactory::NYPizzaToppingFactory;
	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	//TODO: Include a pizza with the name "New York Style Meat Pizza" to the method createPizza
	// 		The corresponding item should be "meat".
	class NYPizzaStore : public PizzaStore
	{
	private:
		Pizza* pizza;
		PizzaToppingFactory* ingredientFactory;
	public:
		~NYPizzaStore()
		{
			if(pizza != nullptr)
				delete pizza;
			if(ingredientFactory != nullptr)
				delete ingredientFactory;
		}

	protected:
		Pizza* createPizza(const std::string& item) override
		{
			pizza = nullptr;
			ingredientFactory = new NYPizzaToppingFactory();

			if (item == "cheese")
			{

				pizza = new CheesePizza(ingredientFactory);
				pizza->setName("New York Style Cheese Pizza");

			}
			else if (item == "veggie")
			{

				pizza = new VeggiePizza(ingredientFactory);
				pizza->setName("New York Style Veggie Pizza");

			}
			else if (item == "clam")
			{

				pizza = new ClamPizza(ingredientFactory);
				pizza->setName("New York Style Clam Pizza");

			}
			else if (item == "pepperoni")
			{

				pizza = new PepperoniPizza(ingredientFactory);
				pizza->setName("New York Style Pepperoni Pizza");

			}
			return pizza;
		}
	};

}


#endif	//#ifndef NYPIZZASTORE
