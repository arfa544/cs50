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
