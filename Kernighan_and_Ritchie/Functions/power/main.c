#include <stdio.h>

int power(int base, int index); // возводит base в степень index 

int main()
{
    printf("First 10 degrees of 2 and -3.\n");

    int i;

    for (i = 1; i < 10; i++)
    {
        printf("%d  %4d  %6d\n", i, power(2,i), power(-3,i));
    }
    
    return (0);
}

int power(int base, int index)
{
    int result, i;
    result = 1;
    if (index >= 1)
    {
        for (i = 1; i <= index; i++)
            result*=base;
    }
    else
    {
        printf("Ur degree must be more than 0.\n");
        return (0);
    }
    return (result);
}