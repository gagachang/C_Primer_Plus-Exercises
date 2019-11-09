/*
 * This program will copy the file.
 * Let the user input the name of source file and
 * the name of target file they want.
 *
 * The program will read the content from source file,
 * and call toupper() in ctype.h to convert the content
 * from lowercase to uppercase.
 * Finally, output the content into target file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAMESIZE 20

int main(void)
{
    char source_filename[NAMESIZE], output_filename[NAMESIZE];
    FILE * fp_input, * fp_output;
    char ch;

    puts("Enter the name of source file you want to copy:");
    scanf("%s", source_filename);

    puts("Enter the name of output file you want:");
    scanf("%s", output_filename);

    while (getchar() != '\n')
        continue;

    if ((fp_input = fopen(source_filename, "r+")) == NULL)
    {
        printf("Can't open %s\n", source_filename);
        exit(1);
    }

    if ((fp_output = fopen(output_filename, "w+")) == NULL)
    {
        printf("Can't open %s\n", output_filename);
        exit(1);
    }

    while ((ch = getc(fp_input)) != EOF)
        putc(toupper(ch), fp_output);

    return 0;
}
