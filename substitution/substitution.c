#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

bool only_alphabets(string s);     //Conforms that the input key is only an alphabet.
char rotate(char c, string key);   //Converts plaintext into ciphertext.
int check_rep_char(string key);    //To check the non occarance of same characters.

int main(int argc, string argv[])
{
    // Check if exactly 1 key is passed.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // Prints the usage if key is not an alphabet.
    if (!only_alphabets(argv[1]))
    {
        printf("Key must only cintain alphabetical characters.\n");
        return 1;
    }

    //To check that the contains 26 characters.
    if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    //To check the non occarance of same characters.
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain reapeated characters.\n");
                return 1;
            }
        }
    }

    //Getting input from user.
    string plaintext = get_string("Plaintext:");

    //Printing output.
    printf("ciphertext:");

    //Converting into ciphertext.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], argv[1]));
    }
    printf("\n");
    return 0;
}

//Conforms that the input key is only an alphabet.
bool only_alphabets(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

//Converts plaintext into ciphertext.
char rotate(char c, string key)
{
    int s = 0;
    //Reservers the lower case.
    if (islower(c))
    {
        c = c - 97;
        s = (int)c;
        if (isupper(key[s]))
        {
            return key[s] + 32;
        }
        else
        {
            return key[s];
        }
    }

    //Reserves the upper case.
    if (isupper(c))
    {
        c = c - 65;
        s = (int)c;
        if (islower(key[s]))
        {
            return key[s] - 32;
        }
        else
        {
            return key[s];
        }
    }
    return c;
}
