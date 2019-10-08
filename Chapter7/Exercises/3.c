/*
 * Read the user's input until input 0
 * Calculate that how many evens in the inputs
 * and print the number ofg evens
 */
#include <stdio.h>
int main(void)
{
    int input;
    int even_number = 0;
    int sum_of_evens = 0;
    int odd_number = 0;
    int sum_of_odds = 0;
    int average_evens = 0;
    int average_odds = 0;

    while ( scanf("%d", &input) && input != 0 )
    {
        if ((input % 2) == 0)
        {
            even_number++;
            sum_of_evens += input;
        }
        else
        {
            odd_number++;
            sum_of_odds += input;
        }
    }
    if (even_number > 0)
        average_evens = sum_of_evens / even_number;
    if (odd_number > 0)
        average_odds = sum_of_odds / odd_number;

    printf("The number of evens is %d, and the average of these even numbers is %d.\n", even_number, average_evens);
    printf("The number of odds is %d, and the average of these odd numbers is %d.\n", odd_number, average_odds);

    return 0;
}
