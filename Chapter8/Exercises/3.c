/*
 * Input a file
 * Calculate how many lowercases and upperceses
 * in this file
 */
#include <stdio.h>
int main(void)
{
    int ch;
    int lowercase = 0;
    int uppercase = 0;

    while ((ch = getchar()) != EOF)
    {
        if (ch > 64 && ch < 91)
            uppercase++;
        else if (ch > 96 && ch < 123)
            lowercase++;
    }

    printf("There are %d lowercases and %d uppercases in this file.\n", lowercase, uppercase);

    return 0;
}

