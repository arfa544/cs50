#include<cs50.h>
#include<stdio.h>

int digits(int n);

int main(void)
{
    // Taking input from user.
    long n = get_long("Enter credit card number: ");
    digits(n);

    int count=0;
    while (n != 0)
    {
        n=n/10;
        count++;
    }

}

int digits(int n);
{
    int count=0;
    while (n != 0)
    {
        n=n/10;
        count++;
    }
    return count;
}