#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int count_letters(string text);

int main(void)
{
    int letters;
    string text = get_string("Text: ");
    printf("%s\n", text);
    letters = count_letters(text);
    printf("%i\n",letters);

}

int count_letters(string text)
{
    int letters = 0;
    for(int i = 0; text[i] != '\0';  i++)
    {
         if(isalpha(text[i]))
         {
             letters++;
         }
    }

    return letters;

}