#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100 // макс размер буфера для getch & ungetch

static char buf[BUFSIZE]; // буфер для ungetch
static int bufp = 0; // след свободная позиция в буфере

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}