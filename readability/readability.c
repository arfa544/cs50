#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

//Funtion prototype.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences;
    float index, L, S ;
    string text = get_string("Text: "); // Input the sentences from the user.
    // To get number of letters.
    letters = count_letters(text);
    // To get number of words.
    words = count_words(text);
    // To get number of sentences.
    sentences = count_sentences(text);
    L = (float)letters / words * 100;
    S = (float)sentences / words * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

// To get number of letters.
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0';  i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// To get number of words.
int count_words(string text)
{
    int words = 1;
    for (int i = 0; text[i] != '\0';  i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// To get number of sentences.
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0';  i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
