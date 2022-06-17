# TODO
from cs50 import get_string


def main():
    # Taking input from user
    text = get_string("Text: ")

    # To get number of letters.
    letters = count_letters(text)

    # To get number of words.
    words = count_words(text)

    # To get number of sentencess.
    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    if (index > 16):
        print("Grade 16+")
    elif (index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


# To get number of letters.
def count_letters(text):
    for i in text:
        if(i.isalpha()):
            letters = letters + 1
    return letters


# To get number of words.
def count_words(text):
    words = 1
    for i in range(len(text)):
        if (text[i] == ' '):
            words = words + 1
    return words


# To get number of sentences.
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if (text[i] == '.' or text[i] == '!' or text[i] == '?'):
            sentences = sentences + 1
    return sentences


main()