/*
 * Modifies example 13.2 reducto.c
 * Hint the user to input the filename rather than
 * using command line arguments.
 */
#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>
#define LEN 9
#define NAMESIZE 5

char * s_gets(char * str, int n);

int main(void)
{
    char filename[NAMESIZE];
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN];    // storage for output filename
    int count = 0;

    // Enter the name of input file
    puts("Enter the name of file you want to reduct (up to 4 characters):");
    s_gets(filename, NAMESIZE);

    // set up input
    if ((in = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                filename);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(name, filename, LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name, ".red");            // append .red
    if ((out = fopen(name, "w")) == NULL)
    {                        // open file for writing
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy date
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
