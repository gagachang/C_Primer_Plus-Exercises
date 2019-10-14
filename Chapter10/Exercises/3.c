/*
 * Write a function that return the maximum value
 * of an array passed to this function.
 */
#include <stdio.h>

void show_array(int arr[], int size);
int find_max(int arr[], int size);

int main(void)
{
    int arr[11] = {1, 10, 9, 4, 6, 5, 7, 0, 2, 3, 8};
    int max_value;

    show_array(arr, sizeof arr / sizeof arr[0]);

    max_value = find_max(arr, sizeof arr / sizeof arr[0]);

    printf("The maximum value in this array is %d.\n", max_value);

    return 0;
}

void show_array(int arr[], int size)
{
    printf("The elements of arr[%d] are ", size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_max(int arr[], int size)
{
    int maximum = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}
