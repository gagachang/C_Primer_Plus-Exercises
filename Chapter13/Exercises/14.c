/*
 * Modifies exercises 12.c
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
 * Before the convertion, we need to compare every value with their neighbors.
 * If the value is more than one difference with the surrounding four points,
 * replace the value with the average of its neighbors.
 * For example:
 *   9                                      9
 * 8 1 9   will changed the center to be  8 8 9
 *   9                                      9
 *
 * Finally, output the 2d char array to screen and an output file.
 *
 * Reads from 12_input and outputs the result to 14_output.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 20
#define COL 31

void Compare(int row, int col, int input[row][col]);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    FILE * fp_input, * fp_output;
    int input[ROW][COL - 1];
    char *output[ROW];

    if ((fp_input = fopen("12_input", "r")) == NULL)
    {
        puts("Can't open intput file.\n");
        exit(1);
    }
    
    if ((fp_output = fopen("14_output", "w+")) == NULL)
    {
        puts("Can't open output file.\n");
        exit(1);
    }

    /* Read the file into input array */
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL - 1; j++)
            fscanf(fp_input, "%d", &input[i][j]);

    /* Compare with neighbors */
    Compare(ROW, COL - 1, input);

    /* Malloc the memory */
    for (int i = 0; i < ROW; i++)
    {
        output[i] = (char *)malloc(sizeof(char) * COL);
        if (!output[i])
        {
            puts("Malloc failed!");
            exit(1);
        }
    }

    /* Initialize char array according to input array */
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j == COL - 1)
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
    for (int i = 0; i < ROW; i++)
        printf("%s\n", output[i]);

    /* Write the array into output file */
    for (int i = 0; i < ROW; i++)
        fprintf(fp_output, "%s\n", output[i]);

    if (fclose(fp_input) || fclose(fp_output))
        printf("Can't close the file\n");

    return 0;
}

void Compare(int row, int col, int input[row][col])
{
    bool up, down, left, right;
    int neighbors, neighbors_value;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            neighbors = neighbors_value = 0;
            up = down = left = right = false;

            /* up */
            if (i == 0)
                up = true;
            else if (abs(input[i - 1][j] - input[i][j]) > 1)
            {
                up = true;
                neighbors++;
                neighbors_value += input[i - 1][j];
            }
            /* down */
            if (i == (row - 1))
                down = true;
            else if (abs(input[i + 1][j] - input[i][j]) > 1)
            {
                down = true;
                neighbors++;
                neighbors_value += input[i + 1][j];
            }
            /* left */
            if (j == 0)
                left = true;
            else if (abs(input[i][j - 1] - input[i][j]) > 1)
            {
                left = true;
                neighbors++;
                neighbors_value += input[i][j - 1];
            }
            /* right */
            if (j == (col - 1))
                right = true;
            else if (abs(input[i][j + 1] - input[i][j]) > 1)
            {
                right = true;
                neighbors++;
                neighbors_value += input[i][j + 1];
            }

            if (up && down && left && right)
                input[i][j] = neighbors_value / neighbors;
        }
    }
}
