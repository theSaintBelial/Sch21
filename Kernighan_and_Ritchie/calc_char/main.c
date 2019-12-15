#include <stdio.h>

//подсчет вводимых символов v1

int calc_char();

int main()
{
    calc_char();

    return (0);
}

int calc_char()
{
    float count;

    for (count = 0; getchar() != EOF; ++count)
        ;
    printf("%.0f\n", count);
    return (0);
}