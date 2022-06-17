# TODO
from cs50 import get_int

def main():

    # Taking input from user.
    n = get_int("Number: ")
    luhn_val = luhn(n)

    # To check all conditions required.
    if (luhn_val == 0):

        # Finding number of digits in credit card.
        


# def luhn(cn):
#     sum = 0
#     for i in range(len(str(cn))):
#         # Add even places
#         if (i % 2 == 0):
#             sum += cn % 10
#         else:
#             digit = 2 * (cn % 10)
#             sum += digit // 10 + digit % 10

#         cn = cn // 10
#     if sum % 10 == 0:
#         print (sum)
#         return True

# validation = luhn(cn)
# if (validation == True):
#     print("Valid")

