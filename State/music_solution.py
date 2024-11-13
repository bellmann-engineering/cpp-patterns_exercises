from abc import ABC, abstractmethod
import enum
import click
from termcolor import colored

class Event(enum.StrEnum):
    """Event enumeration."""
    OnOffPressed = "on / off"
    PlayPausePressed = "play / pause"

class State(ABC):
    """Abstract state class for a state of the music player."""

    def __init__(self, player):
        self.player = player

    @abstractmethod
    def entry(self):
        """Executed when entering the state."""
        raise NotImplementedError("entry() must be implemented in a concrete state")

    @abstractmethod
    def exit(self):
        """Executed when exiting the state."""
        raise NotImplementedError("exit() must be implemented in a concrete state")

    @abstractmethod
    def handle(self, event: Event):
        """Executed when the state is active."""
        raise NotImplementedError("handle() must be implemented in a concrete state")

class OffState(State):
    """State representing the player being off."""

    def entry(self):
        self.player.turn_led_off()

    def exit(self):
        pass

    def handle(self, event: Event):
        if event == Event.OnOffPressed:
            self.player.set_state(PlayingState(self.player))
        elif event == Event.PlayPausePressed:
            print(colored("Cannot play or pause - the player is off", "red"))

class PlayingState(State):
    """State representing the player playing music."""

    def entry(self):
        self.player.turn_led_on()
        self.player.play_music()

    def exit(self):
        self.player.pause_music()

    def handle(self, event: Event):
        if event == Event.OnOffPressed:
            self.player.set_state(OffState(self.player))
        elif event == Event.PlayPausePressed:
            self.player.set_state(PausedState(self.player))

class PausedState(State):
    """State representing the player in a paused state."""

    def entry(self):
        self.player.pause_music()

    def exit(self):
        pass

    def handle(self, event: Event):
        if event == Event.OnOffPressed:
            self.player.set_state(OffState(self.player))
        elif event == Event.PlayPausePressed:
            self.player.set_state(PlayingState(self.player))

class MusicPlayer:
    """Music player class."""

    def __init__(self):
        self.state = OffState(self)
        self._led_on = False
        self.state.entry()  # Initialize with entry action for OffState

    def set_state(self, state: State):
        """Set the current state."""
        self.state.exit()
        self.state = state
        self.state.entry()

    def handle(self, event: Event):
        """Handle an event."""
        self.state.handle(event)

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

    def display_menu(self):
        click.echo("Press a button:\n")
        for i, option in enumerate(Event):
            click.echo(f"{i + 1}. {option}")
        click.echo()
        return click.prompt(
            "Press a button",
            type=int,
            default=1,
            show_default=False,
            prompt_suffix=": ",
        )

if __name__ == "__main__":
    music_player = MusicPlayer()
    options = [option.name for option in Event]

    @click.command()
    def menu_prompt():
        while True:
            option_number = music_player.display_menu()
            if option_number < 1 or option_number > len(options):
                click.echo(f"Invalid option number: {option_number}\n")
            else:
                selected_option = options[option_number - 1]
                event = Event[selected_option]
                music_player.handle(event)
                print(f"Player is in '{music_player.state.__class__.__name__}' state")
                print()

    menu_prompt()
