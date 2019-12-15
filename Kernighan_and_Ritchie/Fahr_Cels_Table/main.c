#include <stdio.h>

/*таблица температур*/ 

int temp_table(int lower, int upper, int step);

int main()
{
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;

    temp_table(lower, upper, step);

    return (0);
}


int temp_table(int lower, int upper, int step)
{
    //celsius = (5.0/9.0) * (fahr-32.0)

    printf("Temp table: \n");

    float fahr, cels;

    fahr = lower;
    while (fahr <= upper)
    {
        cels = (5.0/9.0) * (fahr - 32.0);
        printf("%3.f %4.2f \n", fahr, cels);
        fahr += step;
    }
}
