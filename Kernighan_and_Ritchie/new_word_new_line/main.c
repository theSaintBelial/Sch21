#include <stdio.h>

int nw_nl();    // каждое новое слова ввода выводить на новой строке

int main()   
{
    nw_nl();

    return (0);
}

int nw_nl()
{
    int c;

    printf("New word - new line.\nIN: \n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == ' ')
        {
            putchar('\n');
            continue;
        }
        putchar(c);
    }
    return (0);
}