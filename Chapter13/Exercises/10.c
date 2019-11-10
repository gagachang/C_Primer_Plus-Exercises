/*
 * This program will open a file accroding to a filename that user inputs.
 * And let the user input a position(integer).
 * The program will output the file contents beginning from the position
 * to the end of that line.
 */
#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 21

int main(void)
{
    FILE * fp;
    char filename[NAMESIZE];
    long last_position;
    long position;
    char ch;

    puts("Enter the name of file you want to open:");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s, try again.\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    last_position = ftell(fp);           // get the last position of this file
    rewind(fp);

    puts("Enter a position(integer) you want to print in this file (q to quit):");
    printf("Range in 0 ~ %ld:\n", last_position - 1);
    while (scanf("%ld", &position) == 1)
    {
        if (position >= last_position)   // check that if position is out of the file scope
        {
            puts("Error, the position is out of the file scope, please try again.");
            printf("Enter a position range in 0 ~ %ld (q to quit):\n", last_position - 1);
            continue;
        }

        fseek(fp, position, SEEK_SET);   // go to the designated position of the file

        printf("The contents beginning from the position %ld to the end of this line in %s are:\n", position, filename);
        while ((ch = getc(fp)) != '\n')
            putc(ch, stdout);

        rewind(fp);

        puts("\n\nEnter a position(integer) you want to print in this file (q to quit):");
        printf("Range in 0 ~ %ld:\n", last_position - 1);
    }
    puts("Bye!");

    fclose(fp);

    return 0;
}
