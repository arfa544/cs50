#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int n;
    do
    {
        n=get_int("Enter a number in range 1 to 8: \n");
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<i+1;j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }while(n<0 || n>9);
}