/*
 * This program uses command line arguments.
 * And calculates the power of base.
 *
 * For example: ./14 2 3
 * will print "2 ^ 3 is 8"
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s base exponent\n", argv[0]);
        return 0;
    }

    double base = atof(argv[1]);
    double exponent = atof(argv[2]);

    printf("%.2lf ^ %.2lf is %.2lf\n", base, exponent, pow(base, exponent));

    return 0;
}
