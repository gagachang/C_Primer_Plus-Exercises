/*
 * Write a function that reverse a double array passed to it.
 */
#include <stdio.h>

void show_array(double arr[], int size);
void reverse_array(double arr[], int size);

int main(void)
{
    double arr[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};

    show_array(arr, sizeof arr / sizeof arr[0]);

    reverse_array(arr, sizeof arr / sizeof arr[0]);

    printf("After the reversement:\n");

    show_array(arr, sizeof arr / sizeof arr[0]);

    return 0;
}

void show_array(double arr[], int size)
{
    printf("The elements of arr[%d] are:\n", size);
    for (int i = 0; i < size; i++)
        printf("%.2lf ", arr[i]);
    printf("\n");
}

void reverse_array(double arr[], int size)
{
    double temp[size];

    for (int i = size - 1; i >= 0; i--)
        temp[i] = arr[size - i - 1];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}
