#include <stdio.h>

int NOD(int a, int b);


int main()
{
    int a, b;
    a = 12;
    b = 56;

    printf("NOD = %d ", NOD(a, b));

    return (0);
}


int NOD(int a, int b)
{
    if (a>=b)
    {
        int R;
        R = a % b;
        while (R != 0)
        {
            a = b;
            b = R;
            R = a % b;
        }
    }
    else
    {   
        return (NOD(b, a));
    }
    
    return (b);
}