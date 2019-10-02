#include <stdio.h>
int Square(int n);
int main(void)
{
    int goal;
    int count = 0;
    int sum = 0;

    printf("Enter your goal number: ");
    scanf("%d", &goal);

    while (count++ < goal)
        sum += Square(count);

    printf("sum of 1^2 ~ %d^2 = %d\n", goal, sum);

    return 0;
}

int Square(int n)
{
    return n * n;
}
