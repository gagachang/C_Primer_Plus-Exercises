/* Input the lower bound and upper bound
 * Print each number and its squared and cubed
 * between two bounds.
 */
#include <stdio.h>
int main(void)
{
    int lower_bound, upper_bound;

    printf("Please enter the lower bound and the upper bound\n");
    printf("Lower bound: ");
    scanf("%d", &lower_bound);
    printf("Upper bound: ");
    scanf("%d", &upper_bound);

    printf("Number  Squared  Cubed\n");
    for (int i = lower_bound; i <= upper_bound; i++)
        printf("%6d %8d %6d\n", i, i * i, i * i * i);

    return 0;
}
