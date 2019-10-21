/*
 * This program will generate 100 numbers,
 * and each range in 1-10 randomly.
 * Sorts these numbers decrementally and prints them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBERS 100

void sort(int arr[], int n);
void show_array(const int arr[], int n);

int main(void)
{
    srand((unsigned int) time(0));

    int numbers[NUMBERS];

    for (int i = 0; i < NUMBERS; i++)
        numbers[i] = rand() % 10 + 1;

    sort(numbers, NUMBERS);

    show_array(numbers, NUMBERS);

    return 0;
}

/* Sort array by Bubble sort decrementally */
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void show_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);

        /* ten elements in a line */
        if (i % 10 == 9)
            printf("\n");
    }
}
