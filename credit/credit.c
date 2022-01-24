#include<cs50.h>
#include<stdio.h>

int digits(int n);

int main(void)
{
    int x;
    // Taking input from user.
    long n = get_long("Enter credit card number: ");
    x = digits(n);
    printf("%i \n", x);

    if (x == 15)
    {
        printf("AMEX")
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

