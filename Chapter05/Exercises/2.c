#include <stdio.h>
int main(void)
{
    int input;
    int bound;

    printf("Please enter a number: ");
    scanf("%d", &input);

    bound = input + 10;

    while (input <= bound)
    {
        printf("%5d\n", input);
        input++;
    }
    return 0;
}
