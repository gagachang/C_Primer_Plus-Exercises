/*
 * Use #define to define a macro function that
 * it will calculate the harmonic mean of two numbers.
 */
#include <stdio.h>

#define HARMONIC_MEAN(X,Y)  (1 / (((1 / (X)) + (1 / (Y))) / 2))

int main(void)
{
    double x = 2;
    double y = 5;
    double harmonic_mean;

    harmonic_mean = HARMONIC_MEAN(x, y);

    printf("The harmonic mean of %.2lf and %.2lf is %.2lf\n", x, y, harmonic_mean);

    return 0;
}
