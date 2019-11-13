/*
 * This program will convert binary string 01001001
 * to decimal 73.
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

int binary_to_decimal(char * binary);

int main(void)
{
    char * pbin = "01001001";

    printf("%s is equal to %d\n", pbin, binary_to_decimal(pbin));

    return 0;
}

int binary_to_decimal(char * binary)
{
    int result = 0;
    int bits = strlen(binary);

    for (int i = 0; i < bits; i++)
        result += (binary[i] - '0') * (int) pow(2, bits - i - 1);

    return result;
}
