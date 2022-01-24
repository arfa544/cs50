#include<cs50.h>
#include<stdio.h>

int digits(int n);
int luhn(int n);
int convert_to_single(int num);
int get_first_digits(int no_of_digits, int no_of_places, int n);

int main(void)
{
    int no_of_digits, luhn_val, starting_digits;
    // Taking input from user.
    long n = get_long("Enter credit card number: ");
    //no_of_digits = digits(n);
    //printf("%i \n", no_of_digits);
    luhn_val = luhn(n);
    if (luhn_val == 0)
    {
        no_of_digits = digits(n);
        if (no_of_digits == 15)
        {
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

        else if (no_of_digits == 16)
        {
            starting_digits = get_first_digits(no_of_digits, 2, n);
            if (starting_digits == 51 || starting_digits == 52 || starting_digits == 53 || starting_digits == 54 || starting_digits == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (starting_digits /10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (no_of_digits == 13)
        {
            starting_digits = get_first_digits(no_of_digits, 1, n);
            if (starting_digits == 4)
            {
                printf("VISA");
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
    else
    {
        printf("INVALID\n");
    }
}

int digits(int n)
{
    int count=0;
    while (n != 0)
    {
        n=n/10;
        count++;
    }
    return count;
}

int luhn(int n)
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

int get_first_digits(int no_of_digits, int no_of_places, int n)
{
    for (int i = 0; i < no_of_digits - no_of_places; i++)
    {
        n /= 10;
    }
    return n;
}