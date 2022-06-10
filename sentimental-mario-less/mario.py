# TODO
from cs50 import get_int

# Taking input from user
while (True):
    Height = get_int("Height: ")
    if (Height > 0 or Height < 9):
        break

for i in range(1, Height+1):
    # Printing spaces
    print(" " * (Height - i), end="")
    # Printing '#'
    print("#" * i, end="")
    print()

