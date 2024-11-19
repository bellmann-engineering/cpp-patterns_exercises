#include <iostream>
#include <unordered_map>

// Events for state transitions
enum class Event {
    OnOffPressed,
    PlayPausePressed
};

// Abstract State class
class State {
public:
    virtual ~State() = default;

    virtual void entry() = 0;  // Entering the state
    virtual void exit() = 0;   // Exiting the state
    virtual void handle(Event event, class MusicPlayer& player) = 0;  // Handling events
};

// Context class (MusicPlayer)
class MusicPlayer {
public:
    MusicPlayer();

    ~MusicPlayer();

    void setState(State* new_state);

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
    State* state;
    bool led_on;
};

// Concrete State: Inactive
class Inactive : public State {
public:
    Inactive(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'inactive' state\n";
        player.turnLedOff();
    }

    void exit() override {
        std::cout << "Exiting 'inactive' state\n";
    }

    void handle(Event event, MusicPlayer& player) override {
        if (event == Event::OnOffPressed) {
            std::cout << "OnOffPressed event in 'inactive' state\n";
            player.setState(new On(player));
        }
    }

private:
    MusicPlayer& player;
};

// Concrete State: On
class On : public State {
public:
    On(MusicPlayer& player) : player(player) {}

    void entry() override {
        std::cout << "Entering 'on' state\n";
        player.turnLedOn();
    }

    void exit() override {
        std::cout << "Exiting 'on' state\n";
    }

    void handle(Event event, MusicPlayer& player) override {
        if (event == Event::PlayPausePressed) {
            // TODO: Transition to Playing state
        } else if (event == Event::OnOffPressed) {
            // TODO: Transition to Inactive state
        }
    }

private:
    MusicPlayer& player;
};

// TODO: Add Playing state (inherits from State)

// TODO: Add Paused state (inherits from State)

// MusicPlayer Implementation
MusicPlayer::MusicPlayer() : state(new Inactive(*this)), led_on(false) {
    state->entry();
}

MusicPlayer::~MusicPlayer() {
    delete state;
}

void MusicPlayer::setState(State* new_state) {
    state->exit();
    delete state;
    state = new_state;
    state->entry();
}

void MusicPlayer::handle(Event event) {
    state->handle(event, *this);
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
