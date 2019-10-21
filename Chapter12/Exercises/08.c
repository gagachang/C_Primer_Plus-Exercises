/*
 * pe12-8.c
 * Implement make_array() and show_array()
 *
 * make_array(int elem, int val) will use malloc()
 * to allocate an array with elem elements, and
 * initialize all the value of elements with val.
 *
 * show_array(const int ar[], int n) will print
 * the array ar[], with 8 elements in a line.
 */
#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int * make_array(int elem, int val)
{
    int * arr = (int *) malloc(elem * sizeof(int));

    /* malloc() may fail, need to check it */
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < elem; i++)
        *(arr + i) = val;

    return arr;
}

void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);

        /* Eight elements in a line */
        if (i % 8 == 7)
            printf("\n");
    }
    printf("\n");
}
