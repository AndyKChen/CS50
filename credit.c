#include <cs50.h>
#include <stdio.h>

void print_brand(long long c, int i);
int main(void)
{
    long long n = get_long_long("Number: ");
    long long c = n;
    int x;
    int i;
    int total1 = 0;
    int total2 = 0;

    for(i=1;n>0;i+=1)
    {
        x = n%10;
        n = n/10;
        if(i%2 == 0)
        {
            x = x*2;
            if(x > 9)
            {
                total1 = total1 + x - 9;
            }
            else
            {
                total1 += x;
            }
        }
        else{
            total2+=x;
        }
    }

    if((total1 + total2)%10 == 0)
    {
        print_brand(c, i);
    }
    else
    {
        printf("INVALID\n");
    }
}

void print_brand(long long c, int i)
{

    while(c>=100)
    {
        c = c/10;
    }

    i = i-1;

    if((c == 34 || c==37) && i == 15)
    {
        printf("AMEX\n");
    }
    else if(c/10 == 4 && (i==13 || i==16))
    {
        printf("VISA\n");
    }
    else if(c>50 && c<56 && i == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}