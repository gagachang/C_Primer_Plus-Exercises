/*
 * A program used to copy a file.
 * The file name is input as command line argument.
 * The file must be binary mode.
 *
 * This program will copy file "filename" to "filename_copy"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

void copy(FILE * fc, FILE * fs);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usege: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE * fc, * fs;  // fc for new copy file, fs for source file
    char * copy_filename;
    int size_filename;
    char ch;

    size_filename = strlen(argv[1]);
    copy_filename = (char *) malloc(size_filename + 5);
    if (copy_filename == NULL)
    {
        printf("Malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    copy_filename[size_filename] = '_';
    copy_filename[size_filename + 1] = 'c';
    copy_filename[size_filename + 2] = 'o';
    copy_filename[size_filename + 3] = 'p';
    copy_filename[size_filename + 4] = 'y';
    copy_filename[size_filename + 5] = '\0';

    strncpy(copy_filename, argv[1], size_filename);

    /* Open source and target files */
    if ((fs = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fc = fopen(copy_filename, "w+b")) == NULL)
    {
        printf("Can't open %s \n", copy_filename);
        exit(EXIT_FAILURE);
    }

    printf("Copying from %s to %s ...\n", argv[1], copy_filename);
    copy(fc, fs);

    printf("Done!\n");

    fclose(fs);
    fclose(fc);

    return 0;
}

void copy(FILE * fc, FILE * fs)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, fs)) > 0)
        fwrite(temp, sizeof(char), bytes, fc);
}
