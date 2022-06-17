# TODO
from cs50 import get_int

def main():

    # Taking input from user.
    n = get_int("Number: ")
    luhn_val = luhn(n)

    # To check all conditions required.
    if (luhn_val == 0):

        # Finding number of digits in credit card.
        no_of_digits = digits(n)

        # To check the condition of AMEX card.
        if (no_of_digits == 15):

            # Calling the function to find the starting two digits.
            starting_digits = get_first_digits(no_of_digits, 2, n)
            if (starting_digits == 34 or starting_digits == 37):
                print("AMEX\n")
            else:
                print("INVALID\n")

        # To check the condition of MASTERCARD card or VISA card.
        elif (no_of_digits == 16):
            # Calling the function to find the starting two digits.
            starting_digits = get_first_digits(no_of_digits, 2, n)
            if (starting_digits == 51 or starting_digits == 52 or starting_digits == 53 or starting_digits == 54 or starting_digits == 55):
                printf("MASTERCARD\n")
            elif (starting_digits / 10 == 4):
                printf("VISA\n")
            else:
                printf("INVALID\n")

        # To check the condition of VISA card.
        elif (no_of_digits == 13):

            # Calling the function to find the starting one digit.
            starting_digits = get_first_digits(no_of_digits, 1, n)
            if (starting_digits == 4):
                printf("VISA\n")
            else
                printf("INVALID\n")

        else:
            printf("INVALID\n")

    # Defaults to INVALID.
    else
    {
        printf("INVALID\n");
    }

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

