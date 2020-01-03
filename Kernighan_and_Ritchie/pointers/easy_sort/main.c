#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // макс число строк

char* lineptr[MAXLINES]; // указатели на строки

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void qsort(char* lineptr[], int left, int right);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return (0);
    }
    else
    {
        printf("error: too many strings\n");
        return (1);
    }
}


#define MAXLEN 1000 // макс длина строки

int get_line(char*, int);
char* alloc(int);

int readlines(char* lineptr[], int maxlines) // чтение строк
{
    int len, nlines;

    char* p;
    char line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return (-1);
        else
        {
            line[len - 1] = '\0'; // убираем символ \n
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return (nlines);
}

void writelines(char* lineptr[], int nlines) // печать строк
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int get_line(char* linef, int lim)
{
    printf("\nIN: \n");

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        *(linef + i) = c;
    }
    if (c == '\n')
    {
        *(linef + i) = c;
        i++;
    }
    *(linef + i) = '\0';

    return (i - 1); // длина строки
}

void qsort(char* m[], int left, int right)
{
    int i, last;

    void swap (char* m[], int i, int j);

    if(left >= right)
        return;
    swap(m, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
        if (strcmp(m[i],m[left]) < 0)
            swap(m, ++last, i);
    }
    swap(m, left, last);
    qsort(m, left, last-1);
    qsort(m, last+1, right);
}

void swap(char* m[], int i, int j)
{
    char* temp;
    temp = m[i];
    m[i] = m[j];
    m[j] = temp;
}

#define ALLOCSIZE 10000 // размер доступного пространства

static char allocbuf[ALLOCSIZE]; // память для ALLOC
static char *allocp = allocbuf; // указатель на своб место

char* alloc(int n) // возвращает указатель на n символов
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n; // пространство есть
        return allocp - n; // старое p
    }
    else
    {
        return 0;
    }
}