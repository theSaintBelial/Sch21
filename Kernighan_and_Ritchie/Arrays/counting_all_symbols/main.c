#include <stdio.h>

int count_all(); // подсчет цифр, символов-разделителей и проч симв

int main()
{
    count_all();

    return (0);
}

int count_all()
{
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

    printf("Digits: 0 1 2 3 4 5 6 7 8 9\n");
    printf("Hw mny: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", ndigit[i]);
    }
    printf("\nHw mny Separators: %d\nHw mny other symbs: %d", nwhite, nother);
  
    return (0);
}