/*
 * Design a function order(a, b, c)
 * It will accept three double numbers in pointer type.
 * And find the smallest, median and biggest.
 * Assign the smallest number to first parameter.
 * Assign the median number to second parameter.
 * And the biggest to third parameter.
 */
#include <stdio.h>

void order(double *a, double *b, double *c);

int main(void)
{
    double a, b, c;

    printf("Enter three double numbers: ");
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        while (getchar() != '\n')
            continue;
        printf("Not a double, please try again: ");
    }

    printf("Before the function call, a = %lf, b = %lf and c = %lf.\n", a, b, c);

    order(&a, &b, &c);

    printf("After the funciton call, a = %lf, b = %lf and c = %lf.\n", a, b, c);

    return 0;
}

void order(double *a, double *b, double *c)
{
    double arr[3] = {*a, *b, *c};
    double temp;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    *a = arr[0];
    *b = arr[1];
    *c = arr[2];
}
