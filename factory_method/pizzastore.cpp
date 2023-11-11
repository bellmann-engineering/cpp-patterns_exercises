#include <iostream>
#include <string>

// Forward declarations
class Pizza;
class CheesePizza;
class PepperoniPizza;
class VeggiePizza;

// Pizza base class
class Pizza {
public:
    virtual void bake() const = 0;
};

// CheesePizza class
class CheesePizza : public Pizza {
public:
    void bake() const override {
        std::cout << "Baking a Cheese Pizza." << std::endl;
        // Implement specific baking logic for a cheese pizza
    }
};

// PepperoniPizza class
class PepperoniPizza : public Pizza {
public:
    void bake() const override {
        std::cout << "Baking a Pepperoni Pizza." << std::endl;
    }
};

// VeggiePizza class
class VeggiePizza : public Pizza {
public:
    void bake() const override {
        std::cout << "Baking a Veggie Pizza." << std::endl;
    }
};

// PizzaFactory class
class PizzaFactory {
public:
    Pizza* createPizza(const std::string& type) {
        Pizza* pizza = nullptr;
        if (type == "cheese") {
            pizza = new CheesePizza();
        } else if (type == "pepperoni") {
            pizza = new PepperoniPizza();
        } else if (type == "veggie") {
            pizza = new VeggiePizza();
        }
        return pizza;
    }
};

int main() {
    PizzaFactory pizzaFactory;
    Pizza* cheesePizza = pizzaFactory.createPizza("cheese");
    if (cheesePizza != nullptr) {
        cheesePizza->bake();
        delete cheesePizza; // Don't forget to free the allocated memory
    }

    Pizza* pepperoniPizza = pizzaFactory.createPizza("pepperoni");
    if (pepperoniPizza != nullptr) {
        pepperoniPizza->bake();
        delete pepperoniPizza; // Don't forget to free the allocated memory
    }

    Pizza* veggiePizza = pizzaFactory.createPizza("veggie");
    if (veggiePizza != nullptr) {
        veggiePizza->bake();
        delete veggiePizza; // Don't forget to free the allocated memory
    }

    return 0;
}
