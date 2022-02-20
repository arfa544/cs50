#include <cs50.h>
#include <stdio.h>
#include<ctype.h>

bool only_alphabets(string s);     //Conforms that the input key is only an alphabet.

int main(int argc, string argv[])
{
     // Check if exactly 1 key is passed.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

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