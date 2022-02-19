#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    int key;
    // printf("%i", argc);
    // for(int i=0;i<argc;i++)
    // {
    //     printf("%s", argv[i]);

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

    //coverting key into an integer.
    key = atoi(argv[1]);
    //printf("%i", key);
    string plaintext = get_string("Plaintext:");
    printf("ciphertext:");
    for(int i =0; i < strlen(plaintext); i++)
    {
        rotate(plaintext[i], key);
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    //printf("%lu",strlen(s));
    for(int i = 0; i < strlen(s); i++)
    {
        //printf("strlen 1\n");
        //printf("%d\n", isdigit(s[0]));
        if(isdigit(s[i]))
        {
            return true;
        }
    }
    return false;
}

char rotate(char c, int key)
{
    if (islower(c))
    {
        printf("%c", (((c-97) + key) % 26) + 97);
    }
    else if (isupper(c))
    {
        printf("%c", (((c-65) + key) % 26) + 65);
    }
    else
    {
        printf("%c",c);
    }
    return c;
}