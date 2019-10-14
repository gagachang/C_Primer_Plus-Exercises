/* Calculate the two formulas to Nth */
#include <stdio.h>
double first_formula(double n);
double second_formula(double n);
int main(void)
{
    double n;
    int scanf_result;

    printf("Enter the Nth calculate you want to stop: ");
    scanf_result = scanf("%lf", &n);
    while (scanf_result > 0 && n > 0)
    {
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 4.0/4.0 + ... + 1.0/%.1f is %lf\n", n, first_formula(n));
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 4.0/4.0 + ... +(-) 1.0/%.1f is %lf\n", n, second_formula(n));
        printf("\nEnter the Nth calculate you want to stop: ");
        scanf_result = scanf("%lf", &n);
    }
    printf("Done\n");

    return 0;
}

double first_formula(double n)
{
    double sum = 0;
    for (double i = 1.0; i <= n; i++)
    {
        sum += 1.0 / i;
    }

    return sum;
}

double second_formula(double n)
{
    double sum = 0;
    int index = 1;
    for (double i = 1.0; i <= n; index++, i++)
    {
        if(index % 2 == 1)
            sum += 1.0 / i;
        else
            sum -= 1.0 / i;
    }

    return sum;
}
