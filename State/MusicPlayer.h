#ifndef MUSICPLAYER
#define MUSICPLAYER

#include "State.h"
#include "Event.h"
#include "Inactive.h"


class MusicPlayer
{
	private:
		State* currentState = nullptr;

	public:
		MusicPlayer()
		{
			// TODO: Set initial state to Inactive
			setCurrentState(new Inactive());
		}

		virtual ~MusicPlayer()
		{
			if(currentState != nullptr)
				delete currentState;
		}

		virtual void setCurrentState(State* currentState)
		{
			if (this->currentState != nullptr)
			{
				this->currentState->exit();
			}
			this->currentState = currentState;
			this->currentState->entry();
		}

		virtual State* getCurrentState()
		{
			return currentState;
		}

		virtual void handle(Event event)
		{
			// TODO: Handle State specific behavior here.
			currentState->handle(nullptr, event);
		}
};



#endif	//#ifndef MUSICPLAYER
