"""
State pattern example: Music player and remote control.
Solution
"""
from abc import ABC, abstractmethod
import enum
import click
from termcolor import colored
import colorama

colorama.init()  # used to make ANSI color available


class Event(enum.StrEnum):
    """Event enumeration."""

    OnOffPressed = "on/off"
    PlayPausePressed = "play/pause"


class State(ABC):
    """Abstract state class for a state of the music player."""

    @abstractmethod
    def entry(self):
        """Executed when entering the state."""
        pass

    @abstractmethod
    def exit(self):
        """Executed when exiting the state."""
        pass

    @abstractmethod
    def handle(self, event: Event):
        """Executed when the state is active."""
        pass


class Inactive(State):
    """Concrete state class for the 'inactive' state."""

    def __init__(self, player):
        self.player = player

    def entry(self):
        print(" - Entering 'inactive' state")
        self.player.turn_led_off()

    def exit(self):
        print(" - Exiting 'inactive' state")

    def handle(self, event: Event):
        match event:
            case Event.OnOffPressed:
                print(" - OnOffPressed event in 'inactive' state")
                self.player.set_state(On(self.player))
            case _:
                pass

# TODO: Implement classes for all missing states by inheritance from class State

class Context(ABC):
    """Abstract base class for the Context class of the State pattern."""

    def __init__(self, state: State):
        self.state = state

    def set_state(self, state: State):
        """Set the current state."""
        self.state.exit()
        self.state = state
        self.state.entry()

    def handle(self, event: Event):
        """Handle an event."""
        self.state.handle(event)


class MusicPlayer(Context):
    """Music player class."""

    def __init__(self):
        super().__init__(Inactive(self))
        self._led_on = False

    def turn_led_on(self):
        """Turn the LED on."""
        self._led_on = True
        print(colored("🌕 LED on", "green"))

    def turn_led_off(self):
        """Turn the LED off."""
        self._led_on = False
        print(colored("🌑 LED off", "green"))

    def play_music(self):
        """Play music."""
        print(colored("🔊 Music playing", "green"))

    def pause_music(self):
        """Pause music."""
        print(colored("🔇 Music paused", "green"))

    # Create a function to display the options and prompt for input
    def display_menu(self):
        return click.prompt(
            "\nPress a button (1. on/off; 2. play/pause)",
            type=int,
            default=0,
            show_default=False,
            prompt_suffix=": ",
        )


if __name__ == "__main__":
    # Create a MusicPlayer instance
    music_player = MusicPlayer()
    options = [option.name for option in Event]

    # Create a Click command to run the menu prompt
    @click.command()
    def menu_prompt():
        while True:
            option_number = music_player.display_menu()
            if option_number < 1 or option_number > len(options):
                click.echo(f"Invalid option number: {option_number}\n")
            else:
                selected_option = options[option_number - 1]
                # get the event for the selected option and handle it
                event = Event[selected_option]
                music_player.handle(event)
                print(f"Player is in '{music_player.state.__class__.__name__}' state")

    # run the prompt loop
    menu_prompt()
