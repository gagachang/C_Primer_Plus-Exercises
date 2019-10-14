/*
 * Count that how many characters
 * in a file before EOF.
 */
#include <stdio.h>
int main(void)
{
    int count = 0;
    int ch;

    while ((ch = getchar()) != EOF)
        count++;

    /* except the null terminator */
    printf("There are %d characters in this file.\n", --count);

    return 0;
}
