/*
 * This program will test that
 * how many times a function be called using a for loop.
 *
 * Set the times of loop to 10 and define a static variable
 * in the function. The function needs to return 10 finally.
 */
#include <stdio.h>

int test_function_call();

int main(void)
{
    int count;

    for (int i = 0; i < 10; i++)
        count = test_function_call();

    printf("The function was called %d times.\n", count);

    return 0;
}

int test_function_call()
{
    /* static variable */
    static int count = 0;

    count++;

    return count;
}
