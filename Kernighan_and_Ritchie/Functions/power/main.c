#include <stdio.h>

int power(int base, int index); // возводит base в степень index 

int main()
{
    printf("First 10 degrees of 2 and -3.\n");

    int i;

    for (i = 1; i < 10; i++)
    {
        printf("%d  %4d %6d\n", i, power(2,i), power(-3,i));
    }
    

   //printf("%d\n", power(2, 0));
    return (0);
}

int power(int base, int index)
{
    int result, i;
    for (result = 1; index > 0; index--)
        result*=base;
    return (result);
}