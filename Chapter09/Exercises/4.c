/*
 * Input two double numbers
 * Output their harmonic mean
 */
#include <stdio.h>

double harmonic_mean(double a, double b);

int main(void)
{
    double a, b;
    double harmo_mean;

    printf("Enter two double numbers:\n");
    while (scanf("%lf %lf", &a, &b) != 2)
    {
        scanf("%*s");
        printf("Not a double, please try again: ");
    }

    harmo_mean = harmonic_mean(a, b);

    printf("The harmonic mean of %lf and %lf is %lf.\n", a, b, harmo_mean);

    return 0;
}

double harmonic_mean(double a, double b)
{
    double result;

    result = (1/a + 1/b) / 2;

    return (1 / result);
}
