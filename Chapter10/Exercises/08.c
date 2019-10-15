/*
 * Initialize a double array[7].
 * Use three functions below from Exercise 2
 * to copy the array[3] ~ array[5] into a new three-element array:
 * 1. copy_arr()  will use array subscripts to copy.
 * 2. copy_ptr()  will use a pointer to copy.
 * 3. copy_ptrs() will use two pointers (start/end address of source array).
 *
 * Finally, show_arr() will show the contents of three arrays to varify it.
 */
#include <stdio.h>

void copy_arr(double target[], double source[], int size);
void copy_ptr(double target[], double source[], int size);
void copy_ptrs(double target[], double source[], double * end_of_source);
void show_arr(double target[], int size);

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target1[3];
    double target2[3];
    double target3[3];

    copy_arr(target1, source + 2, 3);
    copy_ptr(target2, source + 2, 3);

    copy_ptrs(target3, source + 2, source + 5);

    /* show the contents of three arrays to test */
    printf("The contents of target1:\n");
    show_arr(target1, 3);

    printf("\nThe contents of target2:\n");
    show_arr(target2, 3);

    printf("\nThe contents of target3:\n");
    show_arr(target3, 3);

    printf("\n");

    return 0;
}

/* Use array subscripts to copy */
void copy_arr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++)
        target[i] = source[i];
}

/* Use a pointer to copy (start address of the two arrays) */
void copy_ptr(double target[], double source[], int size)
{
    for (int i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

/* Use two pointers to copy (start/end address of source array) */
void copy_ptrs(double target[], double source[], double * end_of_source)
{
    for (int i = 0; source < end_of_source; i++, source++)
        target[i] = *source;
}

void show_arr(double target[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%.1lf ", target[i]);
}
