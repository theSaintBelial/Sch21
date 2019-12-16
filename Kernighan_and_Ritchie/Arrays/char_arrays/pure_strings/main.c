#include <stdio.h>

#define MAXLINE 1000

int get_clear_line(); // получает строку из ввода


int main()
{
    get_clear_line();
    return (0);
}

int get_clear_line()
{
    printf("\nIN: \n");

    int c, i, len, lim;

    lim = MAXLINE;

    char linef[lim];

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (c == ' ')
        {
            linef[i] = c;
            while ((c = getchar()) == ' ')
                ;
            i++;
            linef[i] = c;
        }
        else if (c == '\t')
        {
            linef[i] = ' ';
        }
        else
        {
            linef[i] = c;
        }
        
    }
    if (c == '\n')
    {
        linef[i] = c;
        i++;
    }
    linef[i] = '\0';
    
    len = i - 1;
    
    if (len == 0)
    {
        printf("U have entered a zero line. Pls retry.\n");
    }
    else
    {
        printf("\nClear line: %s\nIts length: %d\n", linef, len);
    }
    
    return (0);
}