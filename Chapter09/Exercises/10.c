/*
 * Modify example 9.8
 * Extend the to_binary() function to to_base_n()
 * the base(n) can be 2-10
 * Example: to_base_n(129, 8) will print 201
 */
#include <stdio.h>
void to_base_n(unsigned long number, unsigned long n);

int main(void)
{
    unsigned long number, n;

    printf("Enter an integer(others to quit):\n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Enter the base (2-10): ");
        while (scanf("%lu", &n) == 1)
        {
            if(n < 2 || n > 10)
                printf("Please enter only 2-10: ");
            else
                break;
        }
        printf("%lu base equivalent: ", n);
        to_base_n(number, n);
        putchar('\n');
        printf("Enter an integer (others to quit):\n");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(unsigned long number, unsigned long n)   /* recursive function */
{
    int r;

    r = number % n;
    if (number >= n)
        to_base_n(number / n, n);
    putchar('0' + r);

    return;
}
