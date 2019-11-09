/*
 * This program needs two command line arguments:
 * 1. Target string
 * 2. A file name
 *
 * The program will read the content line by line from the file,
 * and find that if the line contains the target string.
 * If yes, output that line, else continue reading until the
 * end of file.
 *
 * Use strstr() in string.h to search the string in a line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 21

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s target_string file_name\n", argv[0]);
        exit(1);
    }

    FILE *fp;
    char line[SIZE];

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        puts("Can't open the file.");
        exit(1);
    }

    while (fgets(line, SIZE, fp))
    {
        if (strstr(line, argv[1]))
            printf("%s", line);
    }

    if (fclose(fp) != 0)
        printf("Can't close the file.\n");

    return 0;
}
