/*
 * Implement a function that it can add two arrays
 * and put the results in the third array.
 * 
 * This function needs the names of three arrays and size of array.
 */
#include <stdio.h>
#define SIZE 4

void show_array(int arr[], int size);
void add_two_arrays_into_third_array(int arr1[], int arr2[], int arr3[], int size);

int main(void)
{
    int arr1[SIZE] = {2, 4, 5, 8};
    int arr2[SIZE] = {1, 0, 4, 6};
    int arr3[SIZE];

    printf("The contents of arr1:\n");
    show_array(arr1, SIZE);

    printf("\nThe contents of arr2:\n");
    show_array(arr2, SIZE);

    printf("\nThe contents of arr3 before the addition:\n");
    show_array(arr3, SIZE);

    printf("\n\nAdd two arrays into the third array.\n");
    add_two_arrays_into_third_array(arr1, arr2, arr3, SIZE);

    printf("\nThe contents of arr3 after the addition:\n");
    show_array(arr3, SIZE);

    printf("\n");

    return 0;
}

void show_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void add_two_arrays_into_third_array(int arr1[], int arr2[], int arr3[], int size)
{
    for (int i = 0; i < size; i++)
        arr3[i] = arr1[i] + arr2[i];
}
