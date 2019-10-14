/*
 * Initialize a double array[][]
 * Copy it into a new double array.
 * Use one of three functions below from Exercise 2:
 * 1. copy_arr()  will use array subscripts to copy.
 * 2. copy_ptr()  will use a pointer to copy.
 * 3. copy_ptrs() will use two pointers (start/end address of source array).
 *
 * Finally, show_arr() will show the contents of three arrays to varify it.
 */
#include <stdio.h>

void copy_arr(double target[], double source[], int size);
// void copy_ptr(double target[], double source[], int size);
// void copy_ptrs(double target[], double source[], double * end_of_source);
void show_arr(double arr[][5], int rows);

int main(void)
{
    double source[5][5] = { {1.1, 1.2, 1.3, 1.4, 1.5},
                            {2.1, 2.2, 2.3, 2.4, 2.5},
                            {3.1, 3.2, 3.3, 3.4, 3.5},
                            {4.1, 4.2, 4.3, 4.4, 4.5},
                            {5.1, 5.2, 5.3, 5.4, 5.5} };
    double target[5][5];

    for (int row = 0; row < 5; row++)
        copy_arr(target[row], source[row], 5);

    /* show the contents of three arrays to test */
    printf("The contents of target:\n");
    show_arr(target, 5);

    return 0;
}

/* Use array subscripts to copy */
void copy_arr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++)
        target[i] = source[i];
}

void show_arr(double arr[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%.1lf ", arr[i][j]);
        printf("\n");
    }
}
