#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

bool only_digits(string s);     //Conforms that the input key is only a digit.
char rotate(char c, int key);   //Converts plaintext into ciphertext.

int main(int argc, string argv[])
{
    int key;
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
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

//Conforms that the input key is only a digit.
bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

//Converts plaintext into ciphertext.
char rotate(char c, int key)
{
    if (islower(c))
    {
        return ((((c - 97) + key) % 26) + 97);
    }
    else if (isupper(c))
    {
        return ((((c - 65) + key) % 26) + 65);
    }
    else
    {
        return (c);
    }
    // return c;
}