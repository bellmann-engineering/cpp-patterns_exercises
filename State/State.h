#ifndef STATE_H_
#define STATE_H_

#include "Event.h"
#include "MusicPlayer.h"

class State
{
	public:
		virtual void entry() = 0;
		virtual void exit() = 0;
		virtual void handle(MusicPlayer*, Event) = 0;
};


#endif	//#ifndef STATE_H_
