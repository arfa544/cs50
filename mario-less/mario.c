#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // Taking input.
    int n;
    do
    {
        n = get_int("Height: \n");
    }
    while (n <= 0 || n >= 9);

    // Printing mario.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
