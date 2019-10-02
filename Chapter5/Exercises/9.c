#include <stdio.h>
void Temperatures(double F_temperature);
int main(void)
{
    double F_temperature;

    printf("Enter a temperature in Fahrenheit: ");
    
    while (scanf("%lf", &F_temperature) == 1)
    {
        Temperatures(F_temperature);
        printf("Enter next temperature in Fahrenheit: ");
    }
    printf("Done\n");

    return 0;
}

void Temperatures(double F_temperature)
{
    const double Celsius_fraction = 5.0 / 9.0;
    const double Celsius_offset = 32;
    const double Kelvin_offset = 273.16;

    double C_temperature;
    double K_temperature;

    C_temperature = Celsius_fraction * (F_temperature - Celsius_offset);
    K_temperature = C_temperature + Kelvin_offset;

    printf("Fahrenheit temperature is %.2lf \n", F_temperature);
    printf("Equals to Celsius temperature %.2lf\n", C_temperature);
    printf("Equals to Kelvin temperature %.2lf\n", K_temperature);
}
