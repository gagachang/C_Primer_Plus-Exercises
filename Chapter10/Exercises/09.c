/*
 * Initialize a double array[3][5]
 * Implement a "Variable-Length-Array" function
 * to copy this array into another array[3][5].
 *
 * Implement another VLA function to print 
 * the elements of the two arrays.
 */
#include <stdio.h>

void VLA_copy_arr(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void VLA_print_arr(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double source[3][5] = { {1.1, 2.2, 3.3, 4.4, 5.5},
                            {2.2, 3.3, 4.4, 5.5, 6.6},
                            {3.3, 4.4, 5.5, 6.6, 7.7} };
    double target[3][5];

    printf("The contents of the source array:\n");
    VLA_print_arr(3, 5, source);

    printf("\nThe contents of the target array before the copying:\n");
    VLA_print_arr(3, 5, target);

    printf("\nUse VLA function to copy the elements of source array into target array.\n");
    VLA_copy_arr(3, 5, target, source);

    printf("\nThe contents of the target array after the copying:\n");
    VLA_print_arr(3, 5, target);

    return 0;
}


void VLA_copy_arr(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
}

void VLA_print_arr(int rows, int cols, double arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%.1lf ", arr[i][j]);
        printf("\n");
    }
}
