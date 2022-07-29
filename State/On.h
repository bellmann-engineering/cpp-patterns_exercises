#ifndef ON
#define ON

#include <iostream>
#include "State.h"
#include "MusicPlayer.h"

class On: public State
{
	private:
		void LEDOn()
		{
			std::cout << "LED turned On" << std::endl;
		}

		void startTimer()
		{
			std::cout << "Timer Started" << std::endl;
		}
	public:	
		void entry() override
		{		
			LEDOn();
			startTimer();
		}

		void exit() override
		{

		}

		void handle(MusicPlayer* player, Event e) override
		{
			
		}
};



#endif	//#ifndef ON
