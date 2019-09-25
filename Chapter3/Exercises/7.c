#include <stdio.h>
int main(void)
{
    double cm_per_inch = 2.54;
    double height_inch;

    printf("Please input your height in inches: ");
    scanf("%lf", &height_inch);
    printf("Your height is %f cm tall.\n", height_inch * cm_per_inch);
    
    return 0;
}
