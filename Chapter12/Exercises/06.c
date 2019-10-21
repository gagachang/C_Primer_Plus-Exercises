/*
 * This program will generate random numbers range in 1-10.
 * Test for five times, each time will generate 1000 random numbers,
 * And record the results in an array.
 * Print the array to observe the rule of generating random numbers
 * by a random number generator.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_numbers(const int numbers[], int n);
void clean_array(int numbers[], int n);

int main(void)
{
    /* Use number[1] to number[10]  as 1-10 */
    int numbers[11] = {0};

    for (int times = 1; times <= 10; times++)
    {
        /* randomize seed */
        srand((unsigned int) time(0));

        /* count the random number */
        for (int i = 0; i < 1000; i++)
            numbers[rand() % 10 + 1]++;

        printf("Loop %d:\n", times);
        show_numbers(numbers, 10);

        clean_array(numbers, 10);
    }

    return 0;
}
        
void show_numbers(const int numbers[], int n)
{
    printf("Number: ");
    for (int i = 1; i <= n; i++)
        printf(" %3d |", i);

    printf("\n times: ");
    for (int i = 1; i <= n; i++)
        printf(" %3d |", numbers[i]);

    printf("\n");
}

void clean_array(int numbers[], int n)
{
    for (int i = 0; i <= n; i++)
        numbers[i] = 0;
}
