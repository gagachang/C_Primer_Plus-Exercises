/*
 * Read the input string
 * Calculate how many "ei" matched in this string
 */
#include <stdio.h>
int main(void)
{
    int ei_number = 0;
    char prev;
    char current;

    while ((current = getchar()) != '#')
    {
        if ( (current == 'i') && (prev == 'e') )
            ei_number++;

        prev = current;
    }
    printf("There are %d \"ei\" in your input string.\n", ei_number);

    return 0;
}
