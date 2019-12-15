#include <stdio.h>

#define IN 1    //внутри слова
#define OUT 0   //вне слова

int how_many();   // подсчет слов, строк и символов

int main()
{
    how_many();

    return (0);
}

int how_many()
{
    printf("IN: \n");

    int c, nw, nl, nc, state;
    state = OUT;

    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("\nCount of lines: %d \nCount of words: %d \nCount of symbols: %d\n", nl, nw, nc);

    return (0);
}