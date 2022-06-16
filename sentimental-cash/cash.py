# TODO
from cs50 import get_float

def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    int coins = quarters + dimes + nickels + pennies

    // Print total number of coins to give the customer
    printf("%i\n", coins);



def get_cents():
    # Taking input from user
    while (True):
        cents = get_float("Change owed: ")
        if (cents > 0):
            break

def calculate_quarters(cents):
    quarters = 0
    while (cents >= 25):
        cents = cents - 25
        quarter