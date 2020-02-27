
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_itoa(int nbr)
{
    int i;
    char *str;
    long buf;
    int j;
    
    buf = nbr < 0 ? -(long)(nbr) : nbr;
    i = (nbr < 0) ? 2 : 1;
    j = i;
    while (buf / 10 && (buf = buf / 10))
        i++;
    str = (char *)malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    
    if (j > 1)
        str[0] = '-';
    buf = nbr < 0 ? -(long)(nbr) : nbr;
    while(i >= j)
    {
        str[i - 1] = buf % 10 + '0';
        buf /= 10;
        i--;
        printf("str[%d] = %c buf = %ld\n", i, str[i], buf);
    }
    return (str);
}

int main()
{
    int nbr = -2147483648;

    printf("Here is ur nbr: %d\nHere is ur string:%s\n", nbr, ft_itoa(nbr));
    return (0);
}