#include <stdio.h>

//подсчет строк str_count()


int str_count();
int gap_count();
int new_str_count();
int tab_count();

int main()
{
    printf("Count of strings: %d\n", str_count());
    printf("Count of new strings: %d\n", new_str_count());
    printf("Count of gaps: %d\n", gap_count());
    printf("Count of tabs: %d\n", tab_count());
    

    return (0);
}

int str_count()
{
    printf("Counting amount of strings.\n");

    int count, c;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++count;
        }
    }

    return (count);
}

int tab_count()
{
    printf("Counting amount of tabs.\n");

    int count, c;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++count;
        }    
    }
    
    return (count);
}

int gap_count()
{
    printf("Counting amount of gaps.\n");

    int count, c;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++count;
        }
    }
    
    return (count);
}

int new_str_count()
{
    printf("Counting amount of new strings.\n");

    int count, c;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++count;
        }
    }
    if (count != 0)
        return (count - 1);
    return (0);
}