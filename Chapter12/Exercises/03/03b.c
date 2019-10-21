// 03b.c
// compile with 03a.c
//
// This program will get the user's input.
// User need to choose a mode and enter the
// distance and fuel consumption.
//
// In mode 0(metric), the fuel consumption is computed as liters per 100 km.
// In mode 1(US), the fuel consumption is computed as miles per gallon.
//
// The set_mode(), get_info() and show_info() are implemented in 03a.c.
//
// The same as 02, but we can only use auto variables instead of static variables.
#include <stdio.h>
#include "03a.h"
int main(void)
{
    int last_mode, mode;
    int distance;
    double fuel_consumption;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(&last_mode, &mode);
        get_info(mode, &distance, &fuel_consumption);
        show_info(mode, distance, fuel_consumption);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
