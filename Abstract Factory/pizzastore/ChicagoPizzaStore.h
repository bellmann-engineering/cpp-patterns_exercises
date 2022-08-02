#ifndef CHICAGOPIZZASTORE
#define CHICAGOPIZZASTORE

#include "../pizza/CheesePizza.h"
#include "../pizza/ClamPizza.h"
#include "../pizza/PepperoniPizza.h"
#include "../pizza/Pizza.h"
#include "../pizza/VeggiePizza.h"
#include "../toppingfactory/ChicagoPizzaToppingFactory.h"
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
	using ChicagoPizzaToppingFactory = abstractfactorytoppingfactory::ChicagoPizzaToppingFactory;
	using PizzaToppingFactory = abstractfactorytoppingfactory::PizzaToppingFactory;

	//TODO: Create meat pizza and name it using name of the Store
	class ChicagoPizzaStore : public PizzaStore
	{	
	private:
		Pizza* pizza;
		PizzaToppingFactory* ingredientFactory;
	public:
		~ChicagoPizzaStore()
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
			ingredientFactory = new ChicagoPizzaToppingFactory();

			if (item == "cheese")
			{

				pizza = new CheesePizza(ingredientFactory);
				pizza->setName("Chicago Style Cheese Pizza");

			}
			else if (item == "veggie")
			{

				pizza = new VeggiePizza(ingredientFactory);
				pizza->setName("Chicago Style Veggie Pizza");

			}
			else if (item == "clam")
			{

				pizza = new ClamPizza(ingredientFactory);
				pizza->setName("Chicago Style Clam Pizza");

			}
			else if (item == "pepperoni")
			{

				pizza = new PepperoniPizza(ingredientFactory);
				pizza->setName("Chicago Style Pepperoni Pizza");

			}

			return pizza;
		}
	};

}


#endif	//#ifndef CHICAGOPIZZASTORE
