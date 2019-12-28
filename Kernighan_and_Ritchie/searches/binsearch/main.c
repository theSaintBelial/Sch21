#include <stdio.h>

int binsearch(int x, int m[], int len); // бинарный поиск в отсортированном массиве

int main()
{
    int len = 10;

    int m[len];

    int x;

    printf("Enter a number from 0 to %d: ", len);
    scanf("%d", &x);
    printf("Ur Array: ");
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        m[i] = j;
        j+=2;
        printf("%d ", m[i]);
    }
    printf("\nThere is a %d in %d position.", x, binsearch(x, m, len) + 1);

    return (0);
}

int binsearch(int x, int m[], int len)
{
    int low, high, mid;

    low = 0;
    high = len - 1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if (x < m[mid])
            high = mid - 1;
        else if (x > m[mid])
            low = mid + 1;
        else // совпадение найдено
            return (mid);
    }

    return (-1); // совпадений нет
}