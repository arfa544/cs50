#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Taking input.
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n >= 9);

    // Printing mario.
    for (int i = 0; i < n; i++) // For printing new line.
    {
        for (int k = n; k > i + 1; k--) // For printing spaces in between the pyramids.
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) // For printing left #.
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++) // For printing right #.
        {
            printf("#");
        }
        printf("\n");
    }
}

