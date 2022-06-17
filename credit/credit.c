#include<cs50.h>
#include<stdio.h>

int digits(long n);
int luhn(long n);
int convert_to_single(int num);
int get_first_digits(int no_of_digits, int no_of_places, long n);

int main(void)
{
    int no_of_digits, luhn_val, starting_digits;
    // Taking input from user.
    long n = get_long("Enter credit card number: ");

    luhn_val = luhn(n);

    // To check all conditions required.
    if (luhn_val == 0)
    {
        // Finding number of digits in credit card.
        no_of_digits = digits(n);

        // To check the condition of AMEX card.
        if (no_of_digits == 15)
        {
            // Calling the function to find the starting two digits.
            starting_digits = get_first_digits(no_of_digits, 2, n);
            if (starting_digits == 34 || starting_digits == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // To check the condition of MASTERCARD card or VISA card.
        else if (no_of_digits == 16)
        {
            // Calling the function to find the starting two digits.
            starting_digits = get_first_digits(no_of_digits, 2, n);
            if (starting_digits == 51 || starting_digits == 52 || starting_digits == 53 || starting_digits == 54 || starting_digits == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (starting_digits  10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // To check the condition of VISA card.
        else if (no_of_digits == 13)
        {
            // Calling the function to find the starting one digit.
            starting_digits = get_first_digits(no_of_digits, 1, n);
            if (starting_digits == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // Defaults to INVALID.
    else
    {
        printf("INVALID\n");
    }
}

// To find number of digits in credit card number.
int digits(long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

// To give the last digit of sum.
int luhn(long n)
{
    int rem, sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (n != 0)
    {
        // Handling Unit's Digit
        rem = n % 10;
        sum1 += rem;
        n = n / 10;

        // Handling ten's Digit
        rem = (n % 10) * 2;
        rem = convert_to_single(rem);
        sum2 += rem;
        n = n / 10;
    }

    sum = sum1 + sum2;
    rem = sum % 10;

    return rem;
}

// To find sum of individual digits after multiplying with two.
int convert_to_single(int num)
{
    int sum = 0;
    int rem;
    while (num != 0)
    {
        rem = num % 10;
        sum += rem;
        num /= 10;
    }
    return sum;
}

// To get first digits for verification of credit card numbers.
int get_first_digits(int no_of_digits, int no_of_places, long n)
{
    for (int i = 0; i < no_of_digits - no_of_places; i++)
    {
        n /= 10;
    }
    return n;
}