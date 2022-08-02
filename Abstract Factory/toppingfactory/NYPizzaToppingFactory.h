#ifndef NYPIZZATOPPINGFACTORY
#define NYPIZZATOPPINGFACTORY

#include "../topings/pepperoni/Pepperoni.h"
#include "../topings/pepperoni/SlicedPepperoni.h"
#include "../topings/sauce/MarinaraSauce.h"
#include "../topings/sauce/Sauce.h"
#include "../topings/veggies/Garlic.h"
#include "../topings/veggies/Mushroom.h"
#include "../topings/veggies/Onion.h"
#include "../topings/veggies/RedPepper.h"
#include "../topings/veggies/Veggies.h"
#include "../toppings/cheese/Cheese.h"
#include "../toppings/cheese/ReggianoCheese.h"
#include "../toppings/clams/Clams.h"
#include "../toppings/clams/FreshClams.h"
#include "../toppings/dough/Dough.h"
#include "../toppings/dough/ThinCrustDough.h"
// TODO: include meat(y) headers
#include "PizzaToppingFactory.h"
#include <vector>

namespace abstractfactorytoppingfactory
{

	using Pepperoni = abstractfactorytopings::pepperoni::Pepperoni;
	using SlicedPepperoni = abstractfactorytopings::pepperoni::SlicedPepperoni;
	using MarinaraSauce = abstractfactorytopings::sauce::MarinaraSauce;
	using Sauce = abstractfactorytopings::sauce::Sauce;
	using Garlic = abstractfactorytopings::veggies::Garlic;
	using Mushroom = abstractfactorytopings::veggies::Mushroom;
	using Onion = abstractfactorytopings::veggies::Onion;
	using RedPepper = abstractfactorytopings::veggies::RedPepper;
	using Veggies = abstractfactorytopings::veggies::Veggies;
	using Cheese = abstractfactorytoppings::cheese::Cheese;
	using ReggianoCheese = abstractfactorytoppings::cheese::ReggianoCheese;
	using Clams = abstractfactorytoppings::clams::Clams;
	using FreshClams = abstractfactorytoppings::clams::FreshClams;
	using Dough = abstractfactorytoppings::dough::Dough;
	using ThinCrustDough = abstractfactorytoppings::dough::ThinCrustDough;

	class NYPizzaToppingFactory : public PizzaToppingFactory
	{

	public:
		Dough* createDough() override
		{
			return new ThinCrustDough();
		}

		Sauce* createSauce() override
		{
			return new MarinaraSauce();
		}

		Cheese* createCheese() override
		{
			return new ReggianoCheese();
		}

		std::vector<Veggies*> createVeggies() override
		{
			std::vector<Veggies*> veggies =
			{
				new Garlic(),
				new Onion(),
				new Mushroom(),
				new RedPepper()
			};
			return veggies;
		}

		Pepperoni* createPepperoni() override
		{
			return new SlicedPepperoni();
		}

		Clams* createClam() override
		{
			return new FreshClams();
		}

		//TODO: create method

	};

}


#endif	//#ifndef NYPIZZATOPPINGFACTORY
