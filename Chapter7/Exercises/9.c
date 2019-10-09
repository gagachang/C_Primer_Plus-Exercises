/*
 * Enter a number
 * Print all the primers from 1 to the number
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main(void)
{
    int input;
    _Bool isPrime;

    printf("Please enter a number: ");
    scanf("%d", &input);

    printf("The primes from 1 to %d are:\n", input);

    for (int i = 2; i <= input; i++)
    {
        isPrime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if ((i % j) == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}
