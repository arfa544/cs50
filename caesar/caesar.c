#include <cs50.h>
#include <stdio.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}

bool only_digits(string s)
{
    if (s >= 0 && s <=9)
    {
        return true;
    }
    else
    {
        return false;
    }
}