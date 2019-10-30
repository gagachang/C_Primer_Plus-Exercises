/*
 * Define my own usage with C preprocessor
 */
#include <stdio.h>
#include <math.h>

/* Used to square the x */
#define SQUARE(X) ((X) * (X))

/* Used to find maximum of two numbers */
#define MAX(X,Y)  ((X) > (Y) ? (X) : (Y))

/* Used to declare a continuous variables: x1, x2, ... */
#define DEC_X(n)  x ## n

/* Used to print contunous variables: x1 = 1, x2 = 2, ... */
#define PRINT(n) printf("The" #n " = %d\n", x ## n)
