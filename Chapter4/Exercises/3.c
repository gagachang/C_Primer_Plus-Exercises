#include <stdio.h>
int main(void)
{
    float input;

    printf("Please enter the input: ");
    scanf("%f", &input);

    printf("The input is %.1f or %.1e.\n", input, input);
    printf("The input is %+.3f or %.3E.\n", input, input);

    return 0;
}

