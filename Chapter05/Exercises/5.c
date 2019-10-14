#include <stdio.h>
int main(void)
{
    int goal;
    int count = 0;
    int sum = 0;

    printf("Enter your goal number: ");
    scanf("%d", &goal);

    while (count++ < goal)
        sum += count;

    printf("sum of 1~%d = %d\n", goal, sum);

    return 0;
}
