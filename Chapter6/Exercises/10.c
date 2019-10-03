/* Input the lower and upper bound
 * return the sum of square from lower bound to upper bound
 */
#include <stdio.h>
int square(int n);
int sum_of_square(int lower, int upper);
int main(void)
{
    int lower_bound, upper_bound;

    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower_bound, &upper_bound);

    while (lower_bound < upper_bound)
    {
        printf("The sums of the squares from %d to %d is %d\n", square(lower_bound), square(upper_bound), sum_of_square(lower_bound, upper_bound));
        printf("Enter lower and upper integer limits: ");
        scanf("%d %d", &lower_bound, &upper_bound);
    }
    printf("Done\n");

    return 0;
}

int square(int n)
{
    return n * n;
}

int sum_of_square(int lower, int upper)
{
    int sum = 0;

    for (int i = lower; i <= upper; i++)
        sum += square(i);

    return sum;
}
