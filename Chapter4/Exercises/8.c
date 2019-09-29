#include <stdio.h>
#define LITER_PER_GALLON 3.785
#define KILOMETER_PER_MILE 1.609
int main(void)
{
    double miles;
    double gallons;
    double miles_per_gallon;
    double kilometers_per_liter;

    printf("Please enter the miles of your trip: ");
    scanf("%lf", &miles);
    printf("Please enter the gallons of gasoline you spent: ");
    scanf("%lf", &gallons);

    miles_per_gallon = miles / gallons;
    printf("%.1lf miles per gallon.\n", miles_per_gallon);

    kilometers_per_liter = (miles * KILOMETER_PER_MILE) / (gallons * LITER_PER_GALLON);
    printf("\n%.1lf liters of gasoline per 100 kilometers.\n", 100 / kilometers_per_liter);

    return 0;
}
