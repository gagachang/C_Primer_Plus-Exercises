/*
 * An exercise with C variable argument function.
 * Need to implement double * new_d_array(int n, ...)
 *
 * This function uses va_list, va_start(), va_arg(), va_end()
 * in C stdarg.h
 * Call malloc() to allocate memory to put the double numbers
 * into a double array, and return a pointer to that array to main().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main()
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2lf ", ar[i]);
    putchar('\n');
}

double * new_d_array(int n, ...)
{
    va_list valist;
    va_start(valist, n);

    double * temp;
    temp = (double *) malloc(n * sizeof(double));
    if (temp == NULL)
    {
        printf("Malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        temp[i] = va_arg(valist, double);

    va_end(valist);

    return temp;
}
