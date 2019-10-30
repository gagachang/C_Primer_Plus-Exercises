/*
 * Write a function that its arguments are following three types:
 * name of an int array, array size, number of elements want to select
 *
 * The function will randomly select the elements from this array.
 * Each element can only be selected once.
 * The function needs to select elements by the number accroding to third argument.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define ARRAYSIZE 20

void show_array(int arr[], int n);
void randomlySelect(int arr[], int size, int n);

int main(void)
{
    int arr[ARRAYSIZE];
    int select;

    srand((unsigned int) time(0));

    /* Initialize array elements to 1 - ARRAYSIZE */
    for (int i = 0; i < ARRAYSIZE; i++)
        arr[i] = i + 1;

    printf("The elements of array are:\n");
    show_array(arr, ARRAYSIZE);

    printf("\nHow many elements you want to select from the array?\n");
    printf("Enter 1-%d: ", ARRAYSIZE);
    while (scanf("%d", &select) != 1 || select < 1 || select > 20)
    {
        printf("You can only enter 1-%d, please retry it: ", ARRAYSIZE);
        while (getchar() != '\n')
            continue;
    }
    printf("Select %d elements from the array:\n", select);

    randomlySelect(arr, ARRAYSIZE, select);

    return 0;
}

void randomlySelect(int arr[], int size, int n)
{
    bool isSelect[ARRAYSIZE] = {false};
    int count = 0;
    int index;

    while (count < n)
    {
        /* 
         * Randomly select and check that
         * the arr[index] hasn't been selected yet.
         */
        index = rand() % size;
        if (isSelect[index] == false)
        {
            isSelect[index] = true;
            count++;
        }
    }

    for (int i = 0; i < size; i++)
        if (isSelect[i] == true)
            printf("%d ", arr[i]);

    putchar('\n');
}

void show_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    putchar('\n');
}
