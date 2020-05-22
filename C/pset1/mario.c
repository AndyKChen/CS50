#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while(n<0 || n>8);

    int i = 1;

    while(i <= n) {

        for (int j = 0; j < n-i; j++) {
            printf(" ");
        }

        for (int k = 0; k < i; k++) {
            printf("#");
        }

        printf("  ");

        for (int l = 0; l < i; l++) {
            printf("#");
        }

        i++;
        printf("\n");

    }
}
