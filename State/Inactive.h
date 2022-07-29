#ifndef INACTIVE
#define INACTIVE

#include <iostream>
#include "State.h"
#include "MusicPlayer.h"

class Inactive : public State
{

	private:
		void LEDOff()
		{
			std::cout << "LED turned Off" << std::endl;
		}
	public:	
		void entry() override
		{		

		}

		void exit() override
		{
			LEDOff();
		}

		void handle(MusicPlayer* player, Event e) override
		{
			
		}
};

#endif	//#ifndef INACTIVE
