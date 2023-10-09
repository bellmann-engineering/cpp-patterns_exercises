#include "pizza/Pizza.h"
#include "pizzastore/ChicagoPizzaStore.h"
#include "pizzastore/NYPizzaStore.h"
#include "pizzastore/PizzaStore.h"
#include <string>
#include <vector>
#include <iostream>

using Pizza = abstractfactorypizza::Pizza;
using ChicagoPizzaStore = abstractfactorypizzastore::ChicagoPizzaStore;
using NYPizzaStore = abstractfactorypizzastore::NYPizzaStore;
using PizzaStore = abstractfactorypizzastore::PizzaStore;

int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chicagoStore = new ChicagoPizzaStore();

	Pizza* pizza = nyStore->orderPizza("cheese");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("cheese");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("clam");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("clam");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("pepperoni");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("pepperoni");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("veggie");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("veggie");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	pizza = nyStore->orderPizza("meat");
	if(pizza != nullptr)
		std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
	else
		std::cout << "Meatpizza not available!" << std::endl;

	pizza = chicagoStore->orderPizza("meat");
	if(pizza != nullptr)
		std::cout << "Joel ordered a " << pizza->getName() << std::endl;
	else
		std::cout << "Meatpizza not available!" << std::endl;

	if(chicagoStore != nullptr)
		delete chicagoStore;

	if(nyStore != nullptr)
		delete nyStore;

}
