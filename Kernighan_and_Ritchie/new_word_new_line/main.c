#include <stdio.h>

#define IN 1
#define OUT 0

int nw_nl();    // каждое новое слова ввода выводить на новой строке

int main()   
{
    nw_nl();

    return (0);
}

int nw_nl()
{
    int c, state;

    printf("New word - new line.\nIN: \n");

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ')
        {
            state = OUT;
            putchar('\n');
            continue;
        }
        state = IN;
        putchar(c);
    }
    return (0);
}