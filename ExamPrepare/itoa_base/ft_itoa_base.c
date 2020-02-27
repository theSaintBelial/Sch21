
#include <stdlib.h>
#include <stdio.h>

char    *ft_itoa_base(int nbr, int base)
{
    int i;
    long tmp;
    char *str;
    int sign;

    tmp = (nbr < 0) ? -(long)nbr : nbr;
    sign = (nbr < 0 && base == 10) ? -1 : 0;
    i = (sign == -1) ? 2 : 1;
    while ((tmp /= base) > 0)
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    tmp = (nbr < 0) ? -(long)nbr : nbr;
    while (i-- + sign)
    {
        str[i] = (tmp % base >= 10) ? tmp % base + 'A' - 10 : tmp % base + '0';
        tmp /= base;
    }
    (i == 0) ? str[i] = '-' : 0;
    return (str);
}

int main()
{
    int nbr = -12;
    int base = 10;
    printf("Here is ur nbr: %d\nHere is ur base: %d\nHere is ur string: %s\n", nbr, base, ft_itoa_base(nbr, base));
    return (0);
}