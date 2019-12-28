#include <stdio.h>

void shellsort(int m[], int len); // сортировка Шелла
void printArr(int m[], int len); // печать массива

int main()
{
    int m[] = {1,6,5,3,8,9,10,3,29,2};

    int len = 10;

    printf("\nUnsorted Array: ");
    printArr(m, len);

    shellsort(m, len);

    printf("\n  Sorted Array: ");
    printArr(m, len);
    
    return (0);
}

void shellsort(int m[], int len)
{
    int gap, i, j, temp;
    for (gap = len/2; gap > 0; gap/=2)
    {
        for (i = gap; i < len; i++)
        {
            for (j = i - gap; j >= 0 && m[j] > m[j + gap]; j-=gap)
            {
                temp = m[j];
                m[j] = m[j + gap];
                m[j + gap] = temp;
            }
        }
    }
}


void printArr(int m[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%2d ", m[i]);
    }
}