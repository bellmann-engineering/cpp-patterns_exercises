import click
from termcolor import colored

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
            if event == "on / off":
                self.turn_led_on()
                self._state = "On"
        elif self._state == "On":
            if event == "on / off":
                self.turn_led_off()
                self._state = "Inactive"
            elif event == "play / pause":
                self.play_music()
        elif self._state == "Playing":
            if event == "on / off":
                pass
            elif event == "play / pause":
                self.pause_music()
        elif self._state == "Paused":
            if event == "on / off":
                self.turn_led_off()
                self._state = "Inactive"
            elif event == "play / pause":
                self.play_music()
        else:
            print(f"Invalid state: {self._state}")

    def display_menu(self):
        click.echo("Press a button:\n")
        click.echo("1. on / off")
        click.echo("2. play / pause")
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

    @click.command()
    def menu_prompt():
        while True:
            option_number = music_player.display_menu()
            if option_number == 1:
                music_player.handle_event("on / off")
            elif option_number == 2:
                music_player.handle_event("play / pause")
            else:
                click.echo(f"Invalid option number: {option_number}\n")
            print(f"Player is in '{music_player._state}' state\n")

    menu_prompt()
