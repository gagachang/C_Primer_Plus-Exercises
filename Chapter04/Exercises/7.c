#include <stdio.h>
#include <float.h>
int main(void)
{
    double var1 = 1.0/3.0;
    float  var2 = 1.0/3.0;

    printf("%.4lf\n" , var1);
    printf("%.12lf\n", var1);
    printf("%.16lf\n", var1);
    printf("%.4f\n" , var2);
    printf("%.12f\n", var2);
    printf("%.16f\n", var2);

    printf("%.*lf\n", DBL_DIG, var1);
    printf("%.*f\n" , FLT_DIG, var2);

    return 0;
}
