# TODO
from cs50 import get_int

# Taking input from user.
cn = get_int("Number: ")
luhn(cn)
if (luhn(cn) == True):
    print("Valid")

def luhn(cn):
    sum = 0
    for i in range(len(str(cn))):
        # Add even places
        if (i % 2 == 0):
            sum += cn % 10
        else:
            digit = 2 * (cn % 10)
            sum += digit // 10 + digit % 10

        cn = cn // 10
    if sum % 10 == 0:
        print sum
        return True


