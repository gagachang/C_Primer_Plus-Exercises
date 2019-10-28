/*
 * Modifies question 5
 * But the function argument must be the name of month.
 */
#include <stdio.h>
#include <string.h>

struct month {
    char name[10];
    char abbrev[4];
    int days;
    int monumb;
};

struct month months[12] = { {"January",  "jan", 31, 1},
                            {"February", "feb", 28, 2},
                            {"March",    "mar", 31, 3},
                            {"April",    "apr", 30, 4},
                            {"May",      "may", 31, 5},
                            {"June",     "jun", 30, 6},
                            {"July",     "jul", 31, 7},
                            {"August",   "aug", 31, 8},
                            {"September","sep", 30, 9},
                            {"October",  "oct", 31,10},
                            {"November", "nov", 30,11},
                            {"December", "dec", 31,12} };

int getMonthDays(char *);

int main(void)
{
    printf("January has %d days.\n",  getMonthDays("January"));
    printf("March has %d days.\n",    getMonthDays("March"));
    printf("June has %d days.\n",     getMonthDays("June"));
    printf("August has %d days.\n",   getMonthDays("August"));
    printf("December has %d days.\n", getMonthDays("December"));

    return 0;
}

int getMonthDays(char * name)
{
    struct month temp;

    /* find the month accroding to name */
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(name, months[i].name) == 0)
        {
            temp = months[i];
            break;
        }
    }

    return temp.days;
}
