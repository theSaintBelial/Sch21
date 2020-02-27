#include <stdio.h>

/* программа перевода даты день-месяц-год в день-год и наоборот */

char day_number[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_year(int year, int month, int day);
void day_month(int yearday, int year, int *pday, int *pmonth);


int main()
{
    int day, month, year, yearday, key, new_day, new_month;
    char key2;

    key = 5;

    new_day = 0;
    new_month = 0;

    while (key != 0)
    {
        printf("\nHello! This's a program for tranforming different types of dates.\nPlease, enter [1] to enter year-day option or [2] for year-month-day one.\n");
        printf("If u want to quit, press [0]:  ");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            printf("\nEnter a year: ");
            scanf("%d", &year);
            printf("\nEnter a month: ");
            scanf("%d", &month);
            printf("\nEnter a day: ");
            scanf("%d", &day);
            printf("\nTransforming...\n");
            printf("\nNow it is %d/%d.\n", day_year(year, month, day), year);
            break;
        case 2:
            printf("\nEnter a year: ");
            scanf("%d", &year);
            printf("\nEnter a day: ");
            scanf("%d", &yearday);
            day_month(yearday, year, &new_day, &new_month);
            printf("\nNow it is %d/%d/%d\n", new_day, new_month, year);
            break;
        case 0:
            printf("\nC u soon!\n");
            return (0);
        default:
            printf("\nerror: u r a fcking stupid kid!\nOoops, I wanted to say that something had gone wrong. Pls, try again.\n");
            break;
        }
        printf("\nDo u want to run this program again? ([y] or [n]):  ");
        scanf(" %c", &key2);
        if (key2 == 'n')
        {
            printf("\nC u soon!\n");
            return (0);
        }
        if (key2 != 'y' && key2 != 'n')
        {    
            printf("\nerror: exactly, u r a fcking stupid kid!\n");
            break;
        }
    }
    return (0);
}


int day_year(int year, int month, int day)
{
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;   
    
    unsigned int yearday = day;

    for (int i = 0; i < month; i++)
        yearday += day_number[leap][i];	
    return (yearday);
}

void day_month(int yearday, int year, int *pday, int *pmonth)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 0; yearday > day_number[leap][i]; i++)
        yearday -= day_number[leap][i];
    *pmonth = i;
    *pday = yearday; 
}
