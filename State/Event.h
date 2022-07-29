#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <vector>
#include <stdexcept>
#include <utility>

enum Event
{
	PlayPausePressed,
	OnOffPressed,
	SleepTimeExceeded
};

class EventHelper
{
	private:
		static std::vector<std::pair<Event, std::string>> pairs()
		{
			return
			{
				{Event::PlayPausePressed, "PlayPausePressed"},
				{Event::OnOffPressed, "OnOffPressed"},
				{Event::SleepTimeExceeded, "SleepTimeExceeded"}
			};
		}

	public:
		static std::vector<Event> values()
		{
			std::vector<Event> temp;
			for (auto pair : pairs())
			{
				temp.push_back(pair.first);
			}
			return temp;
		}

		static std::string enumName(Event value)
		{
			for (auto pair : pairs())
			{
				if (pair.first == value)
					return pair.second;
			}

			throw std::runtime_error("Enum not found.");
		}

		static int ordinal(Event value)
		{
			std::vector<std::pair<Event, std::string>> temp = pairs();
			for (std::size_t i = 0; i < temp.size(); i++)
			{
				if (temp[i].first == value)
					return i;
			}

			throw std::runtime_error("Enum not found.");
		}

		static Event enumFromString(std::string value)
		{
			for (auto pair : pairs())
			{
				if (pair.second == value)
					return pair.first;
			}

			throw std::runtime_error("Enum not found.");
		}
};

#endif	//#ifndef EVENT_H_
