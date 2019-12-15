#include <stdio.h>

int no_double_gap();

int main()
{
    no_double_gap();

    return (0);
}

int no_double_gap()
{
    int c, count;

    count = 0;

    printf("Say no to double gap.\n");
    printf("In: \n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while ((c = getchar()) == ' ')
                ;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
    return (0);
}