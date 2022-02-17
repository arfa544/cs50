#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // printf("%i", argc);
    // for(int i=0;i<argc;i++)
    // {
    //     printf("%s", argv[i]);
    // }
    string s;

    // Check if exactly 1 key is passed.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if key is digit belonging to 0 and 9 inclusive.
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

bool only_digits(string s)
{
    //printf("%lu",strlen(s));
    if(strlen(s) == 1)
    {
        printf("strlen 1\n");
        printf("%d\n", isdigit(s));
        // if(isdigit(s))
        // {
        //     return true;
        // }
    }
    return false;
}