
#include <stdio.h>

int     is_space(char c)
{
    if (c == '\n' || c == '\t' || c == ' ' || c == '\0')
        return (1);
    return (0);
}

int     is_digit(char c, int str_base)
{
    char str[22] = "0123456789abcdef";
    char str16[5] = "ABCEF";
    int i;

    i = -1;
    while (++i < str_base)
        if (c == str[i])
            return (1);
    i = -1;
    while (++i < 5)
        if (c == str16[i])
            return (1);
    return (0);
}

int     ft_atoi_base(const char *str, int str_base)
{
    int nbr;
    int i;
    int flag;
    int nbr_len;
    int j;
    int base;
    char str[22] = "0123456789abcdef";
    char str16[5] = "ABCEF";
    int kk;

    nbr = 0;
    flag = 1;
    i = 0;
    while(is_space(str[i]))
        i++;
    if (str[i] == '-')
        flag = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    nbr_len = 0;
    while (is_digit(str[i + nbr_len], str_base))
        nbr_len++;
    j = 0;
    base = 1;
    while (--nbr_len >= 0)
    {
        kk = -1;
        while (++kk < str_base)
            if 
        nbr -= (str[nbr_len + i] - '0') * base;
        base *= str_base;
        printf("nbr: %d c: %c\n", nbr, str[nbr_len + i]);
        j++;
    }
    return (-nbr * flag);
}

int main()
{
    char *str = " 986eA kek";
    int str_base = 16;

    printf("Here is your str: %s\nHere is your base: %d\nHere is your nbr: %d\n", str, str_base, ft_atoi_base(str, str_base));
    return (0);
}