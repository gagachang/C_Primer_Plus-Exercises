/*
 * This program will accepts command line arguments.
 * Read the files from arguments and output the contents
 * of each file to screen(terminal).
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s file_name ...\n", argv[0]);
        exit(1);
    }

    FILE * fp;
    int file_count = 1;
    char ch;

    while (file_count <= argc - 1)
    {
        if ((fp = fopen(argv[file_count], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[file_count]);
            exit(1);
        }
        printf("The contents in %s:\n", argv[file_count]);
        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);

        file_count++;
    }

    return 0;
}
