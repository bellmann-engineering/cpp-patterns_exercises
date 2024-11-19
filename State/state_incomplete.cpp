#include <iostream>
#include <unordered_map>

// Events for state transitions
enum class Event {
    OnOffPressed,
    PlayPausePressed
};

// Context class (MusicPlayer)
class MusicPlayer {
public:
    MusicPlayer();

    void setState(MusicPlayer* new_state);

    void turnLedOn() {
        led_on = true;
        std::cout << "🌕 LED on\n";
    }

    void turnLedOff() {
        // TODO: Turn off the LED and print a message
    }

    void playMusic() {
        // TODO: Print "🔊 Music playing"
    }

    void pauseMusic() {
        // TODO: Print "🔇 Music paused"
    }

    void handle(Event event);

private:
    MusicPlayer* state;
    bool led_on;
};

// Concrete State: Inactive
class Inactive : public MusicPlayer {
public:
    Inactive(MusicPlayer& player) : player(player) {}

    void entry() {
        std::cout << "Entering 'inactive' state\n";
        player.turnLedOff();
    }

    void handle(Event event) {
        if (event == Event::OnOffPressed) {
            std::cout << "OnOffPressed event in 'inactive' state\n";
            player.setState(new On(player));
        }
    }

private:
    MusicPlayer& player;
};

// Concrete State: On
class On : public MusicPlayer {
public:
    On(MusicPlayer& player) : player(player) {}

    void entry() {
        std::cout << "Entering 'on' state\n";
        player.turnLedOn();
    }

    void handle(Event event) {
        if (event == Event::PlayPausePressed) {
            // TODO: Transition to Playing state
        } else if (event == Event::OnOffPressed) {
            // TODO: Transition to Inactive state
        }
    }

private:
    MusicPlayer& player;
};

// TODO: Add Playing state
// TODO: Add Paused state

// MusicPlayer Implementation
MusicPlayer::MusicPlayer() : state(new Inactive(*this)), led_on(false) {
    state->entry();
}

void MusicPlayer::setState(MusicPlayer* new_state) {
    state = new_state; // TODO: Handle transitions cleanly
}

void MusicPlayer::handle(Event event) {
    state->handle(event); // TODO: Forward the event to the current state
}

// Main function
int main() {
    MusicPlayer player;

    std::unordered_map<int, Event> menu = {
        {1, Event::OnOffPressed},
        {2, Event::PlayPausePressed}
    };

    while (true) {
        std::cout << "Press a button:\n";
        std::cout << "1. On / Off\n";
        std::cout << "2. Play / Pause\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        if (menu.find(choice) != menu.end()) {
            player.handle(menu[choice]);
        } else {
            std::cout << "Invalid choice.\n";
        }

        std::cout << "\n";
    }

    return 0;
}
