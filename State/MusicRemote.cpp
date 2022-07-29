#include "MusicPlayer.h"
#include "Event.h"
#include <string>
#include <vector>


int main()
{
	MusicPlayer* player = new MusicPlayer();
	std::vector<Event> events = {Event::OnOffPressed, Event::PlayPausePressed};

	for (auto event : events)
	{
		player->handle(event);
	}

	if(player != nullptr)
		delete player;
}
