#ifndef PLAYINGMUSIC
#define PLAYINGMUSIC

#include <iostream>
#include "State.h"
#include "MusicPlayer.h"

// TODO: PlayingMusic State must be conform to the State interface
class PlayingMusic : public State
{
	private:
		void playMusic()
		{
			std::cout << "Playing Music" << std::endl;
		}

		void startTimer()
		{
			std::cout << "Timer Started" << std::endl;
		}

		void entry() override
		{		
			playMusic();
			startTimer();
		}

		void exit() override
		{

		}

		void handle(MusicPlayer* player, Event e) override
		{
			switch(e)
			{
				case Event::PlayPausePressed:
				case Event::SleepTimeExceeded:
					player->setCurrentState(Paused());
					break;
				case Event::OnOffPressed:
					break;
			}
		}
};


#endif	//#ifndef PLAYINGMUSIC
