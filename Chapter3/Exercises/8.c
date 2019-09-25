#include <stdio.h>
int main(void)
{
    double pint;
    double cup;
    double ounce;
    double tablespoon;
    double spoon;

    printf("Please input the cup: ");
    scanf("%lf", &cup);

    pint = cup / 2;
    ounce = cup * 8;
    tablespoon = ounce * 2;
    spoon = tablespoon * 3;

    printf("The %.2lf cup(s) is equal to %.2lf pint(s).\n", cup, pint);
    printf("The %.2lf cup(s) is equal to %.2lf ounce(s).\n", cup, ounce);
    printf("The %.2lf cup(s) is equal to %.2lf tablesppon(s).\n", cup, tablespoon);
    printf("The %.2lf cup(s) is equal to %.2lf spoon(s).\n", cup, spoon);

    return 0;
}
