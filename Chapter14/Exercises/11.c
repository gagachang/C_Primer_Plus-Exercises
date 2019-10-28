/*
 * Desine a function transform, this function contains for arguments:
 * double source[], double target[], int size, double (*func_ptr)(double)
 * This function will transform each element of target array into func_ptr(souce[])
 * Call transform() four times, for math.h two times, and others are designed by us.
 */
#include <stdio.h>
#include <math.h>
#define SIZE 100

void transform(double source[], double target[], int size, double (*func_ptr)(double));
void print(const double target[], int n);

/* Designed functions */
double square(double x);
double cube(double x);

int main(void)
{
    double source[SIZE] = {0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0};
    double target[SIZE];

    /* sin() in math.h */
    printf("Transforming target[] to sin(source[]):\n");
    transform(source, target, SIZE, sin);
    print(target, SIZE);

    /* sqrt() in math.h */
    printf("\nTransforming target[] to sqrt(source[]):\n");
    transform(source, target, SIZE, sqrt);
    print(target, SIZE);

    /* square() */
    printf("\nTransforming target[] to square(source[]):\n");
    transform(source, target, SIZE, square);
    print(target, SIZE);

    /* cube() */
    printf("\nTransforming target[] to cube(source[]):\n");
    transform(source, target, SIZE, cube);
    print(target, SIZE);

    return 0;
}

void transform(double source[], double target[], int size, double (*func_ptr)(double))
{
    for (int i = 0; i < size; i++)
        target[i] = (*func_ptr)(source[i]);
}

void print(const double target[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", target[i]);
        if (i % 10 == 9)
            puts("");
    }
}

double square(double x)
{
    return (x * x);
}

double cube(double x)
{
    return (x * x * x);
}
