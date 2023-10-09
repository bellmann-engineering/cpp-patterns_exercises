from observer_base import *


class Item(Subject):
    """Represents the item (products) of the web shop"""

    def __init__(self, name: str, price: float, in_stock: bool = False):
        """

        Args:
            name (str): name of item
            price (float): price of this item
            in_stock (bool, optional): indicates current availability of this item. Defaults to False.
        """
        super().__init__()
        self.name = name
        self.price = price
        self._in_stock = in_stock

    @property
    def in_stock(self) -> bool:
        """Indicates current availability of this item

        Returns:
            bool: indicating if item is in stock
        """
        return self._in_stock

    @in_stock.setter
    def in_stock(self, value: bool):
        """Sets current in-stock-status of the item as bool

        Args:
            value (bool): True if the item is available, else False
        """
        # notify should only be called if the value has changed from false to true
        if self._in_stock != value:
            self._in_stock = value
            print(
                f" Item {self.name} is now {'in stock' if self._in_stock else 'out of stock'}."
            )
            self.notify()


class Customer(Observer):
    def __init__(
        self,
        name: str,
        email: str,
        phone: str,
        notify_by_email: bool = True,
        notify_by_sms: bool = False,
    ):
        """

        Args:
            name (str): name of the customer
            email (str): email address of customer
            phone (str): phone number of customer
            notify_by_email (bool, optional): Customer want to be notified by email. Defaults to True.
            notify_by_sms (bool, optional): Customer want to be notified by sms. Defaults to False.
        """
        self.name = name
        self.email = email
        self.phone = phone
        self.notify_by_email = notify_by_email
        self.notify_by_sms = notify_by_sms

    def update(self, item, *args, **kwargs):
        """Print a message when the observer receives an update.

        Args:
            subject: The subject that sent the update.
        """
        # TODO: Rewrite the methode update, such that ...
        # ... this costumer is notified by mail or sms depending on the setting of this Custom-Object.
        # ... Use the methodes send_email and send_sms
        # ... The message should include the name of the item, which is now available!
        print(f" A Costumer-Object was updated, but not action was taken!")

    def send_email(self, message: str):
        """Sends the message as an email to this customer

        Args:
            message (str): the message for the costumer
        """
        # Code to send an email to the customer
        print(f" - Email sent to {self.name} ({self.email}): {message}")

    def send_sms(self, message: str):
        """Sends the message as a sms to this customer

        Args:
            message (str): the message for the costumer
        """
        # Code to send a sms to the customer
        print(f" - SMS sent to {self.name} ({self.phone}): {message}")


if __name__ == "__main__":
    # Simulates a the behavior of the webstore if in-stock-status of items changes

    # items in the webstore
    phoenix_feather_wand = Item("Phoenix Feather Wand", 50.0)
    dragon_slayer_sword = Item("Dragon Slayer Sword", 100.0)
    items = [phoenix_feather_wand, dragon_slayer_sword]

    # costumers of the webstore
    alice = Customer(
        "Alice",
        "alice@example.com",
        "123-456-7890",
        notify_by_email=True,
        notify_by_sms=False,
    )
    bob = Customer(
        "Bob",
        "bob@example.com",
        "234-567-8901",
        notify_by_email=False,
        notify_by_sms=True,
    )
    charlie = Customer(
        "Charlie",
        "charlie@example.com",
        "345-678-9012",
        notify_by_email=True,
        notify_by_sms=True,
    )

    # attach customers to items if they are interested
    phoenix_feather_wand.attach(alice)
    phoenix_feather_wand.attach(bob)
    dragon_slayer_sword.attach(charlie)

    # simulation of changing in-stock-status of items

    import random
    import time

    while True:
        print("Updating stock status...")
        for item in items:
            item.in_stock = random.choice([True, False])
        time.sleep(3)
        print()
