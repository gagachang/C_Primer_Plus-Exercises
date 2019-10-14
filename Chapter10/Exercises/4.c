/*
 * Write a function that return the index of maximum value
 * in an array passed to this function.
 */
#include <stdio.h>

void show_array(int arr[], int size);
int find_maximum_index(int arr[], int size);

int main(void)
{
    int arr[11] = {1, 10, 9, 4, 6, 5, 7, 0, 2, 3, 8};
    int index_of_maximum;

    show_array(arr, sizeof arr / sizeof arr[0]);

    index_of_maximum = find_maximum_index(arr, sizeof arr / sizeof arr[0]);

    printf("The index of maximum value in this array is %d.\n", index_of_maximum);

    return 0;
}

void show_array(int arr[], int size)
{
    printf("The elements of arr[%d] are ", size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_maximum_index(int arr[], int size)
{
    int maximum_index = 0;
    int maximum = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maximum)
        {
            maximum_index = i;
            maximum = arr[i];
        }
    }

    return maximum_index;
}
