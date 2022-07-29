#ifndef PAUSED
#define PAUSED

#include <iostream>
#include "State.h"
#include "MusicPlayer.h"

// TODO: Paused State must conform to the State interface
class Paused : public State
{
	private:
		int computeVampirePower()
		{
			return 42;
		}

		void pauseMusic()
		{
			std::cout << "Pausing Music" << std::endl;
		}

		void startTimer()
		{
			std::cout << "Timer Started" << std::endl;
		}
	public:	
		void entry() override
		{		
			computeVampirePower();
			startTimer();
		}

		void exit() override
		{
			pauseMusic();	
		}

		void handle(MusicPlayer* player, Event e) override
		{
			
		}
};


#endif	//#ifndef PAUSED
