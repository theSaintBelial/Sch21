
#include <stdio.h>

int     is_space(char c)
{
    if (c == '\n' || c == '\t' || c == ' ' || c == '\0')
        return (1);
    return (0);
}

int     is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int     ft_atoi(const char *str)
{
    int i;
    int nbr;
    int flag;

    i = 0;
    flag = 1;
    while(is_space(str[i]))
        i++;
    if (str[i] == '-')
        flag = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    nbr = 0;
    while (is_digit(str[i]))
    {    
        nbr = nbr * 10 - str[i] + '0';
        i++;
    }
    return (-nbr * (flag));
}

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("Here is your str: %s\nHere is your nbr: %d\n", argv[1], ft_atoi(argv[1]));
    return (0);
}