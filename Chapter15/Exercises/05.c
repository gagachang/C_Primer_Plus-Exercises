/*
 * This program will rotate an unsigned int by some bits left.
 * (1) Let the user input an unsigned integer, we must check that
 *     the input is in range of 0~4294967294.
 * (2) Let the user input that how many bits to rotate by left.
 *     We must check that the bits is in range of 1~32.
 * (3) Rotates the number and outputs the result.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

/* rotate the *x by bits left */
void rotate_l(unsigned int * x, int bits);

/* decimal to binary */
char * itobs(unsigned int n, char * ps);

/* output binary form */
void show_bstr(const char *);

/* Check that the input is a valid unsigned integer */
int unsigned_int_valid(const char * num_str);

int main(void)
{
    char * num_str;
    unsigned int num;
    int bits;

    printf("Enter an unsigned integer (0~4294967295):\n");
    while (scanf("%s", num_str) != 1 || unsigned_int_valid(num_str) != 1)
        printf("Error, try again.\n");

    printf("Enter how many bits you want to rotate by left (1~32):\n");
    while (scanf("%d", &bits) != 1 || bits < 1 || bits > 32)
        printf("Error, try again.\n");

    num = atoi(num_str);
    rotate_l(&num, bits);

    return 0;
}

void rotate_l(unsigned int * x, int bits)
{
    unsigned int temp;
    char binary[sizeof(unsigned int) * CHAR_BIT];

    itobs(*x, binary);

    printf("Before rotating, the binary form of %u is\n", *x);
    show_bstr(binary);

    temp = *x >> (sizeof(unsigned int) * CHAR_BIT - bits);

    *x = (*x << bits) + temp;

    itobs(*x, binary);

    printf("\n\nAfter rotating %d bits left, the binary form of %u is\n", bits, *x);
    show_bstr(binary);
    puts("");
}

char * itobs(unsigned int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(unsigned int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char * str)
{
    int i = 0;

    while (str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

/* Source from https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c/10204663 */
// 0: invalid, 1: valid
int unsigned_int_valid(const char *s)
{
    while (isspace((unsigned char) *s)) s++;

    if (*s == '-') return 0;
    if (*s == '+') s++;
    if (!isdigit((unsigned char) *s)) return 0;

    errno = 0;
    char * endptr;
    unsigned long ul = strtoul(s, &endptr, 0);

    #if 0
    if (s == endptr) return 0;
    #endif

    while (isspace((unsigned char) *endptr)) endptr++;

    if (*endptr) return 0;

    if (errno) return 0;

    #if ULONG_MAX > UINT_MAX
    // Does 'ul` value exceeds `unsigned` range?
    if (ul > UINT_MAX) return 0;
    #endif

    return 1;
}
