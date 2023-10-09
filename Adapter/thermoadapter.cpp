#include <iostream>

// a class containing only pure virtual methods ≙ interface
class ThermoInterface
{
    public:
        virtual double getTempC() = 0;
        virtual ~ThermoInterface() {}; // important to avoid memory leak by ThermoAdapter
};


class CelciusThermo : public ThermoInterface
{
    public:
        double getTempC() override
        {
            return -20;
        }
    
};

// Legacy component
class FahrenheitThermo
{
    public:
        double getFahrenheitTemperature() 
        {
            std::cout << "FahrenheitThermo called." << "\n";
            return -4; // -4 °F should be -20° C
        }
};

// TODO: Implement ThermoAdapter

int main()
{
    ThermoInterface* ti = new ThermoAdapter();
    std::cout << ti->getTempC() << std::endl;

    if(ti != nullptr)
    {
        delete ti;
        ti = nullptr;
    }
}
