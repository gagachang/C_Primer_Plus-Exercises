#include <stdio.h>
#define CM_PER_INCH 2.54
#define INCH_PER_FOOT 12
int main(void)
{
    float height;
    int foot;
    float inch;

    printf("Enter a height in centimeters: ");
    scanf("%f", &height);

    foot = height / (CM_PER_INCH * INCH_PER_FOOT);
    inch = (height - foot * INCH_PER_FOOT * CM_PER_INCH) / CM_PER_INCH;
    
    printf("%.1f cm = %d feet, %.1f inches\n", height, foot, inch);

    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f", &height);
    while (height > 0)
    {
        foot = height / (CM_PER_INCH * INCH_PER_FOOT);
        inch = (height - foot * INCH_PER_FOOT * CM_PER_INCH) / CM_PER_INCH;
        printf("%.1f cm = %d feet, %.1f inches\n", height, foot, inch);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height);
    }
    printf("bye\n");

    return 0;
}
