from typing import List
from abc import ABC, abstractmethod


class Observer(ABC):
    """Abstract class for observers of subjects.

    Defines the interface that subjects use to notify observers of changes in their state.
    """

    @abstractmethod
    def update(self, subject, *args, **kwargs):
        """Update the observer on a state change of the subject.

        Args:
            subject: The subject that is notifying the observer.
        """
        pass


class Subject(ABC):
    """Base class for subjects that observers can attach to and receive notifications from.

    The subject keeps track of its observers and notifies them when its state changes.
    """

    def __init__(self):
        """Initialize a new Subject with an empty list of observers."""
        self._observers: List[Observer] = []

    def attach(self, observer: Observer):
        """Add an observer to this subject's list of observers.

        Args:
            observer: The observer to attach.
        """
        if observer not in self._observers:
            self._observers.append(observer)

    def detach(self, observer: Observer):
        """Remove an observer from the subject's list of observers.

        Args:
            observer: The observer to detach.
        """
        if observer in self._observers:
            self._observers.remove(observer)

    def notify(self, *args, **kwargs):
        """Notify all observers of a change in the subject's state."""
        for observer in self._observers:
            observer.update(self)


if __name__ == "__main__":
    subject = Subject()
    try:
        observer = (
            Observer()
        )  # Can't instantiate abstract class Observer with abstract method update
    except Exception as e:
        print(e)
