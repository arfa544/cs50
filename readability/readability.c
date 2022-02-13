#include<cs50.h>
#include<stdio.h>
#include<ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s", text);
    count_letters(text);
    printf("%i",letters);
}

int count_letters(string text)
{
    int letters = 0;
    for(int i = 0; text[i] != \0; i++)
    {
         if(isalpha(text))
         {
             letters++;
         }
    }
    printf("%i",letters);
    return letters;
}