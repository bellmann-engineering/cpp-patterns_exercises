#ifndef NYPIZZATOPPINGFACTORY
#define NYPIZZATOPPINGFACTORY

#include "../toppings/pepperoni/Pepperoni.h"
#include "../toppings/pepperoni/SlicedPepperoni.h"
#include "../toppings/sauce/MarinaraSauce.h"
#include "../toppings/sauce/Sauce.h"
#include "../toppings/veggies/Garlic.h"
#include "../toppings/veggies/Mushroom.h"
#include "../toppings/veggies/Onion.h"
#include "../toppings/veggies/RedPepper.h"
#include "../toppings/veggies/Veggies.h"
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

	using Pepperoni = abstractfactorytoppings::pepperoni::Pepperoni;
	using SlicedPepperoni = abstractfactorytoppings::pepperoni::SlicedPepperoni;
	using MarinaraSauce = abstractfactorytoppings::sauce::MarinaraSauce;
	using Sauce = abstractfactorytoppings::sauce::Sauce;
	using Garlic = abstractfactorytoppings::veggies::Garlic;
	using Mushroom = abstractfactorytoppings::veggies::Mushroom;
	using Onion = abstractfactorytoppings::veggies::Onion;
	using RedPepper = abstractfactorytoppings::veggies::RedPepper;
	using Veggies = abstractfactorytoppings::veggies::Veggies;
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
