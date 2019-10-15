/*
 * Read the user's input until '#'
 * And tell user the numer of ' '
 * '\n' and other characters.
 */
#include <stdio.h>
int main(void)
{
    char input;
    int space_char = 0;
    int newLine_char = 0;
    int other_char = 0;

    while ((input = getchar()) != '#')  
    {
        if (input == ' ')
            space_char++;
        else if (input == '\n')
            newLine_char++;
        else
            other_char++;
    }
    printf("Space = %d, Newline = %d, and others = %d.\n", space_char, newLine_char, other_char);

    return 0;
}
