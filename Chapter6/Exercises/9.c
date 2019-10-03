/* Input the two floating numbers
 * Calculate their difference and multiplication
 * Use function to return defference / miltiplication
 */
#include <stdio.h>
double calculate(double input1, double input2);
int main(void)
{
    double input1, input2;

    printf("Please enter two floating numbers: ");

    while (scanf("%lf %lf", &input1, &input2) == 2)
    {
        printf("The result is %lf\n", calculate(input1, input2));
        printf("Please enter two floating numbers: ");
    }

    printf("Done\n");

    return 0;
}

double calculate(double input1, double input2)
{

    double difference;
    double multiple;
    double result;

    difference = input1 - input2;
    multiple = input1 * input2;
    result = difference / multiple;

    return result;
}
