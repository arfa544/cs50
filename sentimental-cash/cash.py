# TODO
from cs50 import get_float

def main():
    # Ask how many cents the customer is owed
    cents = get_cents()


def get_cents():
    # Taking input from user
    while (True):
        cents = get_float("Change owed: ")
        if (cents > 0):
            break