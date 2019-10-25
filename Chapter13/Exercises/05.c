/* 
 * Modified example 13.5 append.c
 * Use command line argument rather than scanf()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s targetfile sourcefile1 (soucefile2 ...)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fa, *fs;        // fa for append file, fs for source file
    int files = 0;        // number of files appended
    char file_src[SLEN];  // name of source file
    int ch;

    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Copy from source files...\n");
    while (argv[files + 2])
    {
        if (strcmp(argv[files + 2], argv[0]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[files + 2], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[files + 2]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[files + 2]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[0]);
            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[files + 1]);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[0]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}
