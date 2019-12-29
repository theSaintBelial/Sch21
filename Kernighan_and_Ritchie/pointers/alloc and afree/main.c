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

void afree(char *p) // освобождает память, на которую указывает p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}                   