/*
 * Write a function that it will return the difference
 * of maximum and minimum values in an double array
 * passed to this function.
 */
#include <stdio.h>

void show_array(double arr[], int size);
double diff_maximum_minimum(double arr[], int size);

int main(void)
{
    double arr[10] = {1.0, 18.0, 13.2, 0.8, 18.1, 16.2, 14.3, 9.2, 7.6, 3.1};
    double diff;

    show_array(arr, sizeof arr / sizeof arr[0]);

    diff = diff_maximum_minimum(arr, sizeof arr / sizeof arr[0]);

    printf("The difference of maximum and minimum value in this array is %.1lf\n", diff);

    return 0;
}

void show_array(double arr[], int size)
{
    printf("The elements of the arr[%d] are:\n", size);
    for (int i = 0; i < size; i++)
        printf("%.1lf ", arr[i]);
    printf("\n");
}

double diff_maximum_minimum(double arr[], int size)
{
    double maximum = arr[0], minimum = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
        if (arr[i] < minimum)
            minimum = arr[i];
    }

    printf("The maximum of this array is %.1lf\n", maximum);
    printf("The minimum of this array is %.1lf\n", minimum);

    return (maximum - minimum);
}
