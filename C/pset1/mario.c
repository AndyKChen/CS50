#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }while(n<0 || n>8);

    int j;
    int k;
    int l;
    int i = 1;
    int x = n-1;

    while (i < n+1)
    {
        for(j=0;j<x;j++)
        {
            printf(" ");
        }
        x--;

        for(k=0;k<i;k++)
        {
            printf("#");
        }
        printf("  ");

        for(l=0;l<i;l++)
        {
            printf("#");
        }

        printf("\n");
        i++;
    }
}

