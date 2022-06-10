# TODO
from cs50 import get_int

while (True):
    Height = get_int("Height: ")
    if (Height > 0 or Height < 9):
        break

for i in range(1,Height+1):
    print(" " * (Height - i), end = "")
    print("#" * i, end = "")
    print()

