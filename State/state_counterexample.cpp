#include <iostream>
#include <string>
#include <unordered_map>

enum class Event {
    OnOffPressed,
    PlayPausePressed
};

enum class PlayerState {
    Inactive,
    On,
    Playing,
    Paused
};

class MusicPlayer {
public:
    MusicPlayer() : state(PlayerState::Inactive), led_on(false) {
        updateState();
    }

    void handle(Event event) {
        switch (state) {
            case PlayerState::Inactive:
                if (event == Event::OnOffPressed) {
                    state = PlayerState::On;
                }
                break;

            case PlayerState::On:
                if (event == Event::OnOffPressed) {
                    state = PlayerState::Inactive;
                } else if (event == Event::PlayPausePressed) {
                    state = PlayerState::Playing;
                }
                break;

            case PlayerState::Playing:
                if (event == Event::PlayPausePressed) {
                    state = PlayerState::Paused;
                }
                break;

            case PlayerState::Paused:
                if (event == Event::PlayPausePressed) {
                    state = PlayerState::Playing;
                } else if (event == Event::OnOffPressed) {
                    state = PlayerState::Inactive;
                }
                break;
        }

        updateState();
    }

private:
    PlayerState state;
    bool led_on;

    void updateState() {
        switch (state) {
            case PlayerState::Inactive:
                turnLedOff();
                std::cout << "Entering 'inactive' state\n";
                break;

            case PlayerState::On:
                turnLedOn();
                std::cout << "Entering 'on' state\n";
                break;

            case PlayerState::Playing:
                playMusic();
                std::cout << "Entering 'playing' state\n";
                break;

            case PlayerState::Paused:
                pauseMusic();
                std::cout << "Entering 'paused' state\n";
                break;
        }
    }

    void turnLedOn() {
        led_on = true;
        std::cout << "🌕 LED on\n";
    }

    void turnLedOff() {
        led_on = false;
        std::cout << "🌑 LED off\n";
    }

    void playMusic() {
        std::cout << "🔊 Music playing\n";
    }

    void pauseMusic() {
        std::cout << "🔇 Music paused\n";
    }
};

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
