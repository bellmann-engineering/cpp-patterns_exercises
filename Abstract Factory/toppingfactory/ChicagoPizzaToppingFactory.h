#ifndef CHICAGOPIZZATOPPINGFACTORY
#define CHICAGOPIZZATOPPINGFACTORY

#include "../topings/pepperoni/Pepperoni.h"
#include "../topings/pepperoni/SlicedPepperoni.h"
#include "../topings/sauce/PlumTomatoSauce.h"
#include "../topings/sauce/Sauce.h"
#include "../topings/veggies/BlackOlives.h"
#include "../topings/veggies/Eggplant.h"
#include "../topings/veggies/Spinach.h"
#include "../topings/veggies/Veggies.h"
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

	using Pepperoni = abstractfactorytopings::pepperoni::Pepperoni;
	using SlicedPepperoni = abstractfactorytopings::pepperoni::SlicedPepperoni;
	using PlumTomatoSauce = abstractfactorytopings::sauce::PlumTomatoSauce;
	using Sauce = abstractfactorytopings::sauce::Sauce;
	using BlackOlives = abstractfactorytopings::veggies::BlackOlives;
	using Eggplant = abstractfactorytopings::veggies::Eggplant;
	using Spinach = abstractfactorytopings::veggies::Spinach;
	using Veggies = abstractfactorytopings::veggies::Veggies;
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
