#include <stdio.h>

#define MAXLINE 1000

int getline(char linef[], int lim); // получает строку
int copy(char to[], char from[]); // копирует
int print_longest_string(); // печатает самую длинную строчку из вводимых

int main()
{
    print_longest_string();

    return (0);
}

int getline(char linef[], int lim)
{
    printf("\nIN: \n");

    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        linef[i] = c;
    }
    if (c == '\n')
    {
        linef[i] = c;
        i++;
    }
    linef[i] = '\0';

    return (i - 1); // длина строки
}

int copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
    return (0);
}

int print_longest_string()
{
    printf("Printing the longest line. \n");

    int len, max_len;
    char line[MAXLINE];
    char longest[MAXLINE];
    max_len = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max_len)
        {
            max_len = len;
            copy(longest, line);
        }
    }

    if (max_len > 0)
    {
        printf("The longest line: %s\nIts length: %d\n\n", longest, max_len);
    }
    
    return (0);
}