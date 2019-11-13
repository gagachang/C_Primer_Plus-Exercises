/*
 * This program will count that how many 1s in binary form of integer.
 * For example: there are 7 1s in integer 127, since 127 = 01111111
 */
#include <stdio.h>

int count_1(int num);

int main(void)
{
    int num = 127;

    printf("There are %d 1s in %d\n", count_1(num), num);

    return 0;
}

int count_1(int num)
{
    int count = 0;

    while (num > 0)
    {
        count++;
        num = num & (num - 1);
    }

    return count;
}
