#include <stdio.h>

void qsort(int m[], int left, int right);


int main()
{
    int arr[] = {1, 4, 2, 9, 4, 5, 6, 3, 0, 4};
    unsigned int len = 10;
    int left = 0;
    int right = len - 1;

    printf("\nUnsorted Array: ");

    for (int i = 0; i < len; i++)
    {
        printf("%3d", arr[i]);
    }

    qsort(arr, left, right);

    printf("\nSorted Array:   ");

    for (int i = 0; i < len; i++)
    {
        printf("%3d", arr[i]);
    }
    
    return (0);
}

void qsort(int m[], int left, int right)
{
    int i, last;

    void swap (int m[], int i, int j);
    if(left >= right)
        return;
    swap(m, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
        if (m[i] < m[left])
            swap(m, ++last, i);
    }
    swap(m, left, last);
    qsort(m, left, last-1);
    qsort(m, last+1, right);
}

void swap(int m[], int i, int j)
{
    int temp;
    temp = m[i];
    m[i] = m[j];
    m[j] = temp;
}