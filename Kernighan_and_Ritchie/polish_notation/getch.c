#include <stdio.h>

#define BUFSIZE 100 // макс размер буфера для getch & ungetch

char buf[BUFSIZE]; // буфер для ungetch
int bufp = 0; // след свободная позиция в буфере

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}