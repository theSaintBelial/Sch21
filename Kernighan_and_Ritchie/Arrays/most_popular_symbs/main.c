#include <stdio.h>

int count_all(); // гистограмма наиболее часто встречающихся цифр и вывод количества др символов

int main()
{
    count_all();

    return (0);
}

int count_all()
{
    printf("Enter ur stuff:\n");

    int i, c, nwhite, nother;

    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; i++)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if (c == '\n' || c == '\t' || c == ' ')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }       
    }

    printf("Hw mny Digits:\n");
    for (i = 0; i < 10; i++)
    {
        printf("\n%d  ", i);
        for(int j = 1; j <= ndigit[i]; j++)
            printf("-");
    }
    printf("\nHw mny Separators: %d\nHw mny other symbs: %d", nwhite, nother);
  
    return (0);
}