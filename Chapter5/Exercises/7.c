#include <stdio.h>
double Cube(double n);
int main(void)
{
    double number;

    printf("Enter a number (double type): ");
    scanf("%lf", &number);

    printf("The cube of the %lf is %lf \n", number, Cube(number));

    return 0;
}

double Cube(double n)
{
    return n * n * n;
}
