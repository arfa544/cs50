#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Taking input.
    int n;
    do
    {
        n = get_int("Enter height of pyramid: \n");
        printf("Height: %i \n",n);
    }
    while (n <= 0 || n >= 9);

    // Printing mario.
    for (int i = 0; i < n; i++) // For printing new line.
    {
        for ( int k = n; k > i+1; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) // For printing #.
        {
            printf("#");
        }
        printf("\n");
    }
}
