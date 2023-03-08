from abc import ABC, abstractmethod

class Observer(ABC):
    """Abstract class for observers of subjects.

    Defines the interface that subjects use to notify observers of changes in their state.
    """

    @abstractmethod
    def update(self, subject):
        """Update the observer on a state change of the subject.

        Args:
            subject: The subject that is notifying the observer.
        """
        raise NotImplementedError("Abstract method update() must be implemented in subclasses.")


class Subject:
    """Base class for subjects that observers can attach to and receive notifications from.

    The subject keeps track of its observers and notifies them when its state changes.
    """

    def __init__(self):
        """Initialize a new Subject with an empty list of observers."""
        self._observers = []

    def attach(self, observer):
        """Add an observer to the subject's list of observers.

        Args:
            observer: The observer to attach.
        """
        self._observers.append(observer)
        print(f"Attached observer {observer} to subject.")

    def detach(self, observer):
        """Remove an observer from the subject's list of observers.

        Args:
            observer: The observer to detach.
        """
        self._observers.remove(observer)
        print(f"Detached observer {observer} from subject.")

    def notify(self):
        """Notify all observers of a change in the subject's state."""
        for observer in self._observers:
            observer.update(self)


class ConcreteObserver(Observer):
    """Concrete observer class that prints a message when it receives an update."""

    def update(self, subject):
        """Print a message when the observer receives an update.

        Args:
            subject: The subject that sent the update.
        """
        print("ConcreteObserver updated.")


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
    observer = ConcreteObserver()
    concrete_subject.attach(observer)
    concrete_subject.set_state("new state")
