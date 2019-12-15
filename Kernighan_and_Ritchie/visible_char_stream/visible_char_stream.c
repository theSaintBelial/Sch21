#include <stdio.h>

int visible_stream();

int main()
{
    visible_stream();

    return (0);
}

int visible_stream()
{
    int c;

    printf("Visible Stream.\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if (c == '\n')
        {
            putchar('\\');
            putchar('n');
            continue;
        }
        if (c == '\b')
        {
            putchar('\\');
            putchar('b');
            continue;
        }
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(c);
    }
    return (0);
}