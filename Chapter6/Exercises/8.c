/* Input two floating numbers
 * Calculate their difference and multiply them
 * return the difference / multiplication
 */
#include <stdio.h>
int main(void)
{
    double input1, input2;
    double difference;
    double multiple;
    double result;

    printf("Please enter two floating numbers: ");

    while (scanf("%lf %lf", &input1, &input2) == 2)
    {
        difference = input1 - input2;
        multiple = input1 * input2;
        result = difference / multiple;
        printf("The result is %lf\n", result);
        printf("Please enter two floating numbers: ");
    }

    printf("Done\n");

    return 0;
}
