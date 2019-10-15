/*
 * (1) Initialize a int array[3][5].
 * (2) Implement a function to print the elements of array.
 * (3) Implement another function that it can multiply an array with two.
 *     The parameter of this function must be the name of array and row number of array.
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5

/* Use VLA function */
void show_2d_array(int rows, int cols, int arr[rows][cols]);

/* The parameter of this function must be the name of array and row number of array */
void multiply_array_with_two(int arr[][COLS], int rows);

int main(void)
{
    int arr[ROWS][COLS] = { {1, 2, 3, 4, 5},
                            {2, 3, 4, 5, 6},
                            {3, 4, 5, 6, 7}  };

    printf("The contents of array before multiplication:\n");
    show_2d_array(ROWS, COLS, arr);

    printf("\nMultiply this array with two.\n");
    multiply_array_with_two(arr, ROWS);

    printf("\nThe contents of array after multiplication:\n");
    show_2d_array(ROWS, COLS, arr);

    return 0;
}

void show_2d_array(int rows, int cols, int arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }
}

void multiply_array_with_two(int arr[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] *= 2;
}
