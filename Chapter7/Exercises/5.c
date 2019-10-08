/*
 * Read the user's input until '#'
 * Replace '.' with '!'
 * Replace '!' with "!!"
 * Finally, tell user how many replacement happened
 * (Use switch...case...)
 */
#include <stdio.h>
int main(void)
{
    char input;
    int replacement = 0;

    while ((input = getchar()) != '#')
    {
        switch (input)
        {
            case '.' :  replacement++;
                        break;
            case '!' :  replacement++;
                        break;
        }
    }
    printf("There are %d replacements.\n", replacement);

    return 0;
}
