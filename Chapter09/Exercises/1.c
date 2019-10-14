/*
 * Design a function min(x, y)
 * It will return the smaller between two doubles.
 */
#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x, y;

    printf("Please input two double numbers:\n");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        scanf("%*s");
        printf("Sorry, please try again.\n");
        printf("Please input two double numbers: \n");
    }
    printf("The smaller number of %lf and %lf is %lf.\n", x, y, min(x, y));

    return 0;
}

double min(double x, double y)
{
    return (x < y ? x : y); 
}
