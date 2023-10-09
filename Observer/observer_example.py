from observer_base import *


class ConcreteObserver(Observer):
    """Concrete observer class that prints a message when it receives an update."""

    def update(self, subject):
        """Print a message when the observer receives an update.

        Args:
            subject: The subject that sent the update.
        """
        print(f"ConcreteObserver updated. State of subject is {subject._state}.")


class ConcreteSubject(Subject):
    """Concrete subject class with a state that observers can be notified of."""

    def __init__(self):
        """Initialize a new ConcreteSubject with an empty list of observers and a None state."""
        super().__init__()
        self._state = None

    def set_state(self, state):
        """Set the subject's state to a new value and notify all observers.

        Args:
            state: The new state value.
        """
        self._state = state
        self.notify()


if __name__ == "__main__":
    concrete_subject = ConcreteSubject()
    print(f"ConcreteSubject created.")
    observer = ConcreteObserver()
    print(f"ConcreteObserver created.")
    concrete_subject.attach(observer)
    concrete_subject.set_state("NEW STATE")
