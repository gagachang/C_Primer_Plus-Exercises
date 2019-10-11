/*
 * Uses loop to implement Fibonacci()
 */
#include <stdio.h>

unsigned long Fibonacci(unsigned n);

int main(void)
{
    unsigned n;

    printf("Enter which item in Fibonacci you want: ");
    while (scanf("%u", &n) != 1)
    {
        scanf("%*s");
        printf("This is not a number, please retry it: ");
    }

    printf("The %u item of Fibonacci sequence is %lu.\n", n, Fibonacci(n));

    return 0;
}

unsigned long Fibonacci(unsigned n)
{
    int f1 = 1, f2 = 1;
    unsigned long result = 0;

    if (n < 3)
        return 1;

    for (int i = 3; i <= n; i++)
    {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }

    return result;
}
