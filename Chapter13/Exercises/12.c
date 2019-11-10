/*
 * This program will read a file into an 2d int array.
 * And convert the content of 2d int array to 2d char array.
 *
 * For example:
 * 0 in int array will be coverted to ' ' into char array.
 * 1 will be '.'
 * 2 will be '\''
 * ...
 * 9 will be
 *
 * Finally, output the 2d char array to screen and an output file.
 *
 * Reads from 12_input and outputs the result to 12_output.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    FILE * fp_input, * fp_output;
    int input[20][30];
    char output[20][31];

    if ((fp_input = fopen("12_input", "r")) == NULL)
    {
        puts("Can't open intput file.\n");
        exit(1);
    }
    
    if ((fp_output = fopen("12_output", "w+")) == NULL)
    {
        puts("Can't open output file.\n");
        exit(1);
    }

    /* Read the file into input array */
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 30; j++)
            fscanf(fp_input, "%d", &input[i][j]);

    /* Initialize char array according to input array */
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (j == 30)
            {
                output[i][j] = '\0';
                continue;
            }

            switch(input[i][j])
            {
                case 0 : output[i][j] = ' ';
                         break;
                case 1 : output[i][j] = '.';
                         break;
                case 2 : output[i][j] = '\'';
                         break;
                case 3 : output[i][j] = ':';
                         break;
                case 4 : output[i][j] = '~';
                         break;
                case 5 : output[i][j] = '*';
                         break;
                case 6 : output[i][j] = '=';
                         break;
                case 7 : output[i][j] = '@';
                         break;
                case 8 : output[i][j] = '%';
                         break;
                case 9 : output[i][j] = '#';
                         break;
                default: break;
            }
        }
    }

    /* Output the array to screen */
    for (int i = 0; i < 20; i++)
        printf("%s\n", output[i]);

    /* Write the array into output file */
    for (int i = 0; i < 20; i++)
        fprintf(fp_output, "%s\n", output[i]);

    if (fclose(fp_input) || fclose(fp_output))
        printf("Can't close the file\n");

    return 0;
}
