// 03a.c
// compile with 03b.c
#include <stdio.h>
#include "03a.h"

/* Use a variable "last_mode" to store the last state */
void set_mode(int * last_mode, int * mode)
{
    if (*mode > 1)
    {
        switch (*last_mode)
        {
            case 0 : printf("Invalid mode specified. Mode 0(metric) used.\n");
                     *mode = *last_mode;
                     break;
            case 1 : printf("Invalid mode specified. Mode 1(US) used.\n");
                     *mode = *last_mode;
                     break;
        }
    }
    else
        *last_mode = *mode;
}

void get_info(int mode, int * distance, double * fuel_consumption)
{
    switch (mode)
    {
        case 0 : printf("Enter distance traveled in kilometers: ");
                 scanf("%d", distance);
                 printf("Enter fuel consumed in liters: ");
                 scanf("%lf", fuel_consumption);
                 break;
        case 1 : printf("Enter distance traveled in miles: ");
                 scanf("%d", distance);
                 printf("Enter fuel consumed in gallons: ");
                 scanf("%lf", fuel_consumption);
                 break;
    }
}

void show_info(int mode, int distance, double fuel_consumption)
{
    switch (mode)
    {
        case 0 : printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel_consumption / distance * 100);
                 break;
        case 1 : printf("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel_consumption);
                 break;
    }
}
