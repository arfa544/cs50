# TODO
from cs50 import get_int

# Taking input from user.
cn = get_int("Number: ")

def luhn(cn):
    sum = 0
    for i in range(len(str(cn))):
        # Add even places
        if (i % 2 == 0):
            


