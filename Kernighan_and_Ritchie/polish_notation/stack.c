#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 // макс глубина стека

int sp = 0; // следующая свободная позиция в стеке
double val[MAXVAL]; // стек

void push(double f) // положить новое значение в стек
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, %d cannot be placed\n", f);
}

double pop(void) // взять с вершины стека и выдать в качестве результата
{
    if (sp > 0)
        return (val[--sp]);
    else
    {
        printf("error: stack is empty\n");
        return (0.0);
    }
}