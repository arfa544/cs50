#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences;
    int l = letters / words * 100;
    int s = sentences / words * 100;
    string text = get_string("Text: ");
    printf("%s\n", text);
    letters = count_letters(text);
    printf("%i\n",letters);
    words = count_words(text);
    printf("%i\n",words);
    sentences = count_sentences(text);
    printf("%i\n",sentences);
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

int count_words(string text)
{
    int words = 1;
    for(int i = 0; text[i] != '\0';  i++)
    {
         if(text[i] == ' ')
         {
             words++;
         }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for(int i = 0; text[i] != '\0';  i++)
    {
         if(text[i] == '.' || text[i] == '!' || text[i] == '?')
         {
             sentences++;
         }
    }
    return sentences;
}
