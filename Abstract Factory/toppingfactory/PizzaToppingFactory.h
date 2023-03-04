#ifndef PIZZATOPPINGFACTORY
#define PIZZATOPPINGFACTORY

#include "../toppings/pepperoni/Pepperoni.h"
#include "../toppings/sauce/Sauce.h"
#include "../toppings/veggies/Veggies.h"
#include "../toppings/cheese/Cheese.h"
#include "../toppings/clams/Clams.h"
#include "../toppings/dough/Dough.h"
#include <vector>

namespace abstractfactorytoppingfactory
{

	using Pepperoni = abstractfactorytoppings::pepperoni::Pepperoni;
	using Sauce = abstractfactorytoppings::sauce::Sauce;
	using Veggies = abstractfactorytoppings::veggies::Veggies;
	using Cheese = abstractfactorytoppings::cheese::Cheese;
	using Clams = abstractfactorytoppings::clams::Clams;
	using Dough = abstractfactorytoppings::dough::Dough;

	//TODO: Add the required method to the following interface
	class PizzaToppingFactory
	{

	public:
		virtual Dough* createDough() = 0;
		virtual Sauce* createSauce() = 0;
		virtual Cheese* createCheese() = 0;
		virtual std::vector<Veggies*> createVeggies() = 0;
		virtual Pepperoni* createPepperoni() = 0;
		virtual Clams* createClam() = 0;
	};

}


#endif	//#ifndef PIZZATOPPINGFACTORY
