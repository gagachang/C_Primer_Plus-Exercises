/*
 * Modify the 13.c
 * The function parameter must be Variable-Length-Array.
 *
 * Implement four functions below:
 * (a) Input the double numbers into a 3x5 array.
 * (b) Calculate the average of a row.
 * (c) Calculate the average of all the array elements.
 * (d) Find the maximum value in this array.
 *
 * For (b), it can only calculate for a row in a time.
 * We must use a loop to call (b) three times.
 *
 * Other functions must use a 3x5 array as their parameter.
 * (c) and (d) must return the result to the caller (main function).
 */
#include <stdio.h>
#define ROWS 3
#define COLS 5

/* The four functions below are implemented by VLA */
void input_array(int rows, int cols, double arr[rows][cols]);
double average_per_row(int size, double arr[size]);
double average_total(int rows, int cols, double arr[rows][cols]);
double get_maximum_value(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double arr[ROWS][COLS];

    /* (a) */
    input_array(ROWS, COLS, arr);

    printf("\n");

    /* (b) */
    for (int i = 0; i < ROWS; i++)
        printf("The average of row %d is %lf\n", i, average_per_row(COLS, arr[i]));

    /* (c) */
    double total = 0.0;
    for (int i = 0; i < ROWS; i++)
        total += average_per_row(COLS, arr[i]);
    printf("\nThe average of all the array elements is %lf\n", total / ROWS);

    /* (d) */
    printf("\nThe maximum value in this array is %lf\n", get_maximum_value(ROWS, COLS, arr));

    /* (e) */
    printf("\nDone!!!\n");

    return 0;
}

void input_array(int rows, int cols, double arr[rows][cols])
{
    printf("Enter the elements of this array:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%lf", &arr[i][j]);
}

double average_per_row(int size, double arr[size])
{
    double result = 0.0;

    for (int i = 0; i < size; i++)
        result += arr[i];

    return (result / size);
}

double average_total(int rows, int cols, double arr[rows][cols])
{
    double result = 0.0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result += arr[i][j];

    return (result / (rows * cols));
}

double get_maximum_value(int rows, int cols, double arr[rows][cols])
{
    /* default arr[0][0] is maximum */
    double maximum = arr[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            maximum = (arr[i][j] > maximum) ? arr[i][j] : maximum ;
}
