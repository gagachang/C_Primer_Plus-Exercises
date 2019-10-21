// 02a.c
// compile with 02b.c
#include <stdio.h>
#include "02a.h"

/* Three static variables with file scope and internal linkage */
static int current_mode;
static int distance;
static double fuel_consumption;

void set_mode(int mode)
{
    if (mode > 1)
    {
        if (current_mode == 0)
            printf("Invalid mode specified. Mode 0(metric) used.\n");
        else
            printf("Invalid mode specified. Mode 1(US) used.\n");
    }
    else
        current_mode = mode;
}

void get_info()
{
    switch (current_mode)
    {
        case 0 : printf("Enter distance traveled in kilometers: ");
                 scanf("%d", &distance);
                 printf("Enter fuel consumed in liters: ");
                 scanf("%lf", &fuel_consumption);
                 break;
        case 1 : printf("Enter distance traveled in miles: ");
                 scanf("%d", &distance);
                 printf("Enter fuel consumed in gallons: ");
                 scanf("%lf", &fuel_consumption);
                 break;
    }
}

void show_info()
{
    switch (current_mode)
    {
        case 0 : printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel_consumption / distance * 100);
                 break;
        case 1 : printf("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel_consumption);
                 break;
    }
}
