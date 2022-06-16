# TODO
from cs50 import get_float

def main():
    cents = get_cents(cents)


def get_cents(cents):
    # Taking input from user
    while (True):
        cents = get_float("Change owed: ")
        if (cents > 0):
            break