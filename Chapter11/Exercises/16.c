/*
 * This program will accept command line arguments
 * Reads the input file, and changes the contents of the file
 * according to the following arguments:
 * (1) -p : print the file contents
 * (2) -u : change all the letters to upper cases
 * (3) -l : change all the letters to lower cases
 *
 * For example: 
 * A temp file "abcde", call ./16 -p -u < temp
 * will print ABCDE.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s (-p|-u|-l) < filename\n", argv[0]);
        return 0;
    }

    int p = 1, u = 0, l = 0;    

    int i = 1;
    while (argv[i])
    {
        if (strcmp("-p", argv[i]) == 0)
            p = 1;
        if (strcmp("-u", argv[i]) == 0)
            u = 1;
        if (strcmp("-l", argv[i]) == 0)
            l = 1;
        i++;
    }

    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (u)
            ch = toupper(ch);
        if (l)
            ch = tolower(ch);
        if (p)
            putchar(ch);
    }

    return 0;
}
