from typing import List
from abc import ABC, abstractmethod


class Subject(ABC):
    """
    The Subject interface declares a set of methods for managing subscribers.
    """

    def __init__(self):
        self._observers: List[Observer] = []

    def register(self, observer: "Observer"):
        """
        Attach an observer to the subject.
        """
        if observer not in self._observers:
            self._observers.append(observer)

    def unregister(self, observer: "Observer"):
        """
        Detach an observer from the subject.
        """
        if observer in self._observers:
            self._observers.remove(observer)

    def notify(self, *args, **kwargs):
        """
        Notify all observers about an event.
        """
        for observer in self._observers:
            observer.update(self)


class Observer(ABC):
    """
    The Observer interface declares the update method, used by subjects.
    """

    @abstractmethod
    def update(self, subject, *args, **kwargs):
        """
        Receive update from subject.
        """
        raise NotImplementedError(
            "Abstract method update() must be implemented in subclasses."
        )

