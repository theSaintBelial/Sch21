#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100 // макс размер операнда

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;   
        case '*':
            push(pop() * pop());
            break;   
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;   
        case '/':
            if((op2 = pop()) != 0.0)
                push(pop() / op2);
            else
                printf("error: division by zero\n");
            break;
        case '\n':
            printf("Result is: %.8g\n", pop());
            break;        
        default:
            break;
        }
    }
    return (0);
}