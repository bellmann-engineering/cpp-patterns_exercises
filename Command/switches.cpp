#include <iostream>
#include <vector>
using namespace std;

const int MaxCommand = 5;

enum Receiver
{
	LIGHT = 0, FAN, DOOR, OVEN, NONE
}; 

// Command Interface
class LightSwitchCommand
{
	// TODO: 1. Create the Command Interface
};
 
// Receiver Class
class Light 
{
	// TODO: 3. Create the Receiver (“Entity Objects”) 
}; 


// Command for turning on the light
class FlipUpCommand : public LightSwitchCommand 
{
	// TODO: 2(a). Create a ConcreteCommand (“Control Objects”) 
};
 
// Command for turning off the light
class FlipDownCommand : public LightSwitchCommand 
{
	// TODO: 2(b). Create another ConcreteCommand (“Control Objects”) 

};

// Invoker 
// Stores the ConcreteCommand object 
class Switch 
{
	private:
		vector<LightSwitchCommand*> mOnCommand;
		vector<LightSwitchCommand*> mOffCommand;
	
	public:
		// TODO: 4. Create the Invoker (“Boundary Objects”)

};

// Client
int main() 
{
	// Receiver 
	Light* light = new Light;

	// concrete Command objects 
	FlipUpCommand* lightOn = new FlipUpCommand(light);
	FlipDownCommand* lightOff = new FlipDownCommand(light);

	// invoker objects
	Switch* sw = new Switch;

	// TODO: 5. Create the Client

	return 0;
}