/*
 * Read the user's input until '#'
 * Replace '.' with '!'
 * Replace '!' with "!!"
 * Finally, tell user how many replacement happened
 * (Use if...else...)
 */
#include <stdio.h>
int main(void)
{
    char input;
    int replacement = 0;

    while ((input = getchar()) != '#')
    {
        if (input == '.')
            replacement++;
        else if (input == '!')
            replacement++;
    }
    printf("There are %d replacements.\n", replacement);

    return 0;
}
