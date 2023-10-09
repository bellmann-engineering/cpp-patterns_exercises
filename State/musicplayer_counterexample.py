"""
State pattern counterexample: Music player and remote control.
"""
import click
import enum
from termcolor import colored
import colorama

colorama.init()  # used to make ANSI color available


class Event(enum.StrEnum):
    """Event enumeration."""

    OnOffPressed = "on/off"
    PlayPausePressed = "play/pause"


class MusicPlayer:
    """Music player class."""

    def __init__(self):
        self._state = "Inactive"
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
        self._state = "Playing"

    def pause_music(self):
        """Pause music."""
        print(colored("🔇 Music paused", "green"))
        self._state = "Paused"

    def handle_event(self, event):
        """Handle an event."""
        if self._state == "Inactive":
            if event == "on/off":
                self.turn_led_on()
                self._state = "On"
        elif self._state == "On":
            if event == "on/off":
                self.turn_led_off()
                self._state = "Inactive"
            elif event == "play/pause":
                self.play_music()
        elif self._state == "Playing":
            if event == "on/off":
                pass
            elif event == "play/pause":
                self.pause_music()
        elif self._state == "Paused":
            if event == "on/off":
                self.turn_led_off()
                self._state = "Inactive"
            elif event == "play/pause":
                self.play_music()
        else:
            print(f"Invalid state: {self._state}")

    def display_menu(self):
        return click.prompt(
            "\nPress a button (1. on/off; 2. play/pause)",
            type=int,
            default=0,
            show_default=False,
            prompt_suffix=": ",
        )


if __name__ == "__main__":
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
                music_player.handle_event(event)

    # run the prompt loop
    menu_prompt()
