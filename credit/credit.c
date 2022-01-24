#include<cs50.h>
#include<stdio.h>

int digits(int n);
int luhn(int n);
int convert_to_single(int num);

int main(void)
{
    int x, luhn_val;
    // Taking input from user.
    long n = get_long("Enter credit card number: ");
    //x = digits(n);
    //printf("%i \n", x);
    luhn_val = luhn(n);
    if (luhn_val == 0)
    {
        if ( )
        printf("AMEX\n");
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