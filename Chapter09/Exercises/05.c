/*
 * Design a larger_of(x, y)
 * It will find the larger number between x and y.
 * And assign this number to both x and y.
 */
#include <stdio.h>

void larger_of(double *x, double *y);

int main(void)
{
    double x, y;

    printf("Enter two double numbers: ");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        while (getchar() != '\n')
            continue;
        printf("Not a double number, try again: ");
    }

    printf("x = %lf and y = %lf.\n", x, y);

    larger_of(&x, &y);

    printf("After the function call, x = %lf and y = %lf.\n", x, y);

    return 0;
}

void larger_of(double *x, double *y)
{
    *x > *y ? (*y = *x) : (*x = *y);
}
