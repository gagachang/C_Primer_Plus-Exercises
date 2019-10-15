#include <stdio.h>
int main(void)
{
    double second_of_year = 3.156e7;
    double year;

    printf("Please input your age (year): ");
    scanf("%lf", &year);
    printf("The seconds of your year is %f seconds.\n", second_of_year * year);

    return 0;
}
