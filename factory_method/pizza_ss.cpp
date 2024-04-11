#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Pizza {
private:
    std::string type;
    std::string toppings;
    int size;

public:
    Pizza(const std::string& type, const std::string& toppings, int size)
        : type(type), toppings(toppings), size(size) {}

    static Pizza* createPizza(const std::string& pizzaDetails) {
        std::vector<std::string> parts;
        std::stringstream ss(pizzaDetails);
        std::string token;
        while (std::getline(ss, token, '|')) {
            parts.push_back(token);
        }

        if (parts.size() == 3) {
            return new Pizza(parts[0], parts[1], std::stoi(parts[2]));
        } else {
            std::cerr << "Invalid pizza details." << std::endl;
            return nullptr;
        }
    }

    void describe() const {
        std::cout << "Type: " << type << ", Toppings: " << toppings << ", Size: " << size << std::endl;
    }
};

int main() {
    // Creating a Pizza object using constructor
    Pizza p1("Margherita", "Cheese", 12);
    p1.describe();

    // Creating a Pizza object using factory method
    std::string pizzaDetails = "Pepperoni|Veggies|16";
    Pizza* p2 = Pizza::createPizza(pizzaDetails);
    if (p2) {
        p2->describe();
        delete p2;
    }

    return 0;
}
