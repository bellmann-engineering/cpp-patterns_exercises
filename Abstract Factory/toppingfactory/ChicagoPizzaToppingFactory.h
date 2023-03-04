#ifndef CHICAGOPIZZATOPPINGFACTORY
#define CHICAGOPIZZATOPPINGFACTORY

#include "../toppings/pepperoni/Pepperoni.h"
#include "../toppings/pepperoni/SlicedPepperoni.h"
#include "../toppings/sauce/PlumTomatoSauce.h"
#include "../toppings/sauce/Sauce.h"
#include "../toppings/veggies/BlackOlives.h"
#include "../toppings/veggies/Eggplant.h"
#include "../toppings/veggies/Spinach.h"
#include "../toppings/veggies/Veggies.h"
#include "../toppings/cheese/Cheese.h"
#include "../toppings/cheese/MozzarellaCheese.h"
#include "../toppings/clams/Clams.h"
#include "../toppings/clams/FrozenClams.h"
#include "../toppings/dough/Dough.h"
#include "../toppings/dough/ThickCrustDough.h"

// TODO: include meat(y) headers
#include "PizzaToppingFactory.h"
#include <vector>

namespace abstractfactorytoppingfactory
{

	using Pepperoni = abstractfactorytoppings::pepperoni::Pepperoni;
	using SlicedPepperoni = abstractfactorytoppings::pepperoni::SlicedPepperoni;
	using PlumTomatoSauce = abstractfactorytoppings::sauce::PlumTomatoSauce;
	using Sauce = abstractfactorytoppings::sauce::Sauce;
	using BlackOlives = abstractfactorytoppings::veggies::BlackOlives;
	using Eggplant = abstractfactorytoppings::veggies::Eggplant;
	using Spinach = abstractfactorytoppings::veggies::Spinach;
	using Veggies = abstractfactorytoppings::veggies::Veggies;
	using Cheese = abstractfactorytoppings::cheese::Cheese;
	using MozzarellaCheese = abstractfactorytoppings::cheese::MozzarellaCheese;
	using Clams = abstractfactorytoppings::clams::Clams;
	using FrozenClams = abstractfactorytoppings::clams::FrozenClams;
	using Dough = abstractfactorytoppings::dough::Dough;
	using ThickCrustDough = abstractfactorytoppings::dough::ThickCrustDough;

	class ChicagoPizzaToppingFactory : public PizzaToppingFactory
	{

	public:
		Dough* createDough() override
		{
			return new ThickCrustDough();
		}

		Sauce* createSauce() override
		{
			return new PlumTomatoSauce();
		}

		Cheese* createCheese() override
		{
			return new MozzarellaCheese();
		}

		std::vector<Veggies*> createVeggies() override
		{
			std::vector<Veggies*> veggies =
			{
				new BlackOlives(),
				new Spinach(),
				new Eggplant()
			};
			return veggies;
		}

		Pepperoni* createPepperoni() override
		{
			return new SlicedPepperoni();
		}

		Clams* createClam() override
		{
			return new FrozenClams();
		}

		// TODO: create method
	};

}


#endif	//#ifndef CHICAGOPIZZATOPPINGFACTORY
