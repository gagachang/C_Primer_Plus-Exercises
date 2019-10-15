#include <stdio.h>
int main(void)
{
    double water_quality = 3.0e-23;
    double quart_quality = 950;
    double quart;

    printf("Please input the quart: ");
    scanf("%lf", &quart);
    printf("The quality of water in %f quarts is %f gs\n", quart, quart * quart_quality / water_quality);

    return 0;
}
