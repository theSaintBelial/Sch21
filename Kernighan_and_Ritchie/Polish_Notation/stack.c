#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 // макс глубина стека

static int sp = 0; // след позиция в стеке
static double val[MAXVAL]; // стек

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, %g cannot be placed\n", f);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack is empty\n");
        return (0.0);
    }
}