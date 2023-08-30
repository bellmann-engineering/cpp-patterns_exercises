#include <iostream>

// a class containing only pure virtual methods ≙ interface
class ThermoInterface
{
    public:
        virtual double getTempC() = 0;
};


class CelciusThermo : public ThermoInterface
{
    public:
        double getTempC() override
        {
            return -20;
        }
    
};

// Lecacy component
class FahrenheitThermo
{
    public:
        double getFahrenheitTemperature() 
        {
            return -4; // -4 °F should be -20° C
        }
    
};

int main()
{
    // TODO: Implement ThermoAdapter
    ThermoInterface* ti = new ThermoAdapter();
    std::cout << ti->getTempC() << std::endl;

    if(ti != nullptr)
       delete ti;
}
