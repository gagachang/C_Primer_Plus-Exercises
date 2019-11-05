/*
 * This program will implement binary search.
 * Declare an array of positive integers.
 * Sort it and let the user input a terget number.
 * If the target number is in the array, return 1,
 * otherwise return 0.
 *
 * Use qsort() in c stdlib.h to sort the array.
 * Enter negative integer to quit the program.
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int comp(const void * a, const void * b);
void show_array(int arr[], int size);

int binary_search(int arr[], int size, int target);

int main(void)
{
    int arr[SIZE] = {10, 3, 2, 1, 6, 8, 9, 7, 4, 5,
                     12, 0, 13, 15, 18, 20, 22, 25, 33, 21};
    int target;
    int result;

    qsort(arr, SIZE, sizeof(int), comp);

    puts("The elements of array are:");
    show_array(arr, SIZE);

    while (1)
    {
        puts("Enter the positive integer you want to search (enter negative to quit): ");
        while (scanf("%d", &target) != 1)
        {
            puts("You should only enter the number, try again.");
            puts("Enter the integer you want to search: ");
        }
        if (target == -1)
            break;

        result = binary_search(arr, SIZE, target);
        if (result)
            printf("%d is in the array.\n", target);
        else
            printf("%d is not in the array.\n", target);
    }
    puts("Bye.");

    return 0;
}

int comp(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}

void show_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int binary_search(int arr[], int size, int target)
{
    int start = 0, end = size - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (arr[middle] == target)
            return 1;
        else if (arr[middle] < target)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return 0;
}
