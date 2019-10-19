/*
 * This program will accept command line argumants
 * And print the argumants conversely.
 *
 * For example: ./13 see you later
 * Will print "later you see"
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s string string ...\n", argv[0]);
        return 0;
    }

    /* Count that how many strings in command line arguments */
    int i = 0;
    while (argv[i])
        i++;

    i--;
    /* Print the strings conversely */
    while (i > 0)
        printf("%s ", argv[i--]);

    puts("");

    return 0;
}
