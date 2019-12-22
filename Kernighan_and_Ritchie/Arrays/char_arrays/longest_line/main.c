#include <stdio.h>

#define MAXLINE 1000

int getline(char linef[], int lim); // получает строку
int copy(char to[], char from[]); // копирует
int print_longest_string(); // печатает самую длинную строчку из вводимых
int print_more_50(); // печатает все строки, содержащие больше 80 символов
int reverse_line(char line[], int len); // печатает реверсивный вариант line

int main()
{
    //print_longest_string();
    //print_more_50();

    int len = 23;

    char line[] = "ghbhvthtvhbtbvh vhtbhvt";

    reverse_line(line, len);

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
        printf("The longest line: %s\nIts length: %d\n", longest, max_len);
    }
    
    return (0);
}

int print_more_50()
{
    printf("\nPrinting all lines more than 50 symbols.\n");

    int len, max_len;
    char line[MAXLINE];

    max_len = 0;

    while((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max_len)
        {
            max_len = len;
        }
        if (len > 50)
        {
            printf("\nLine more than 50 symbols: %s\nIts length: %d", line, len);
        }
    }
    if (max_len < 50)
        printf("U haven't entered any line more than 50 symbols.\n");

    return (0);
}

int reverse_line(char line[], int len)
{
    int i, j;

    char reverse[len];

    j = 0;

    for(i = len - 1; i >= 0; i--)
    {
           reverse[i] = line[j];
           j++;
    }
    printf("Reverse line: %s", reverse);
    return (0);
}