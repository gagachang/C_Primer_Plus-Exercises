// 02b.c
// compile with 02a.c
//
// This program will get the user's input.
// User need to choose a mode and enter the
// distance and fuel consumption.
//
// In mode 0(metric), the fuel consumption is computed as liters per 100 km.
// In mode 1(US), the fuel consumption is computed as miles per gallon.
//
// The set_mode(), get_info() and show_info() are implemented in 02a.c.
#include <stdio.h>
#include "02a.h"
int main(void)
{
    int mode;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
