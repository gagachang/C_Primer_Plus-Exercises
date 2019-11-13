/*
 * This program will check that if a specific bit in
 * binary form of an integer is 1 or 0.
 *
 * int_valid() will check that if user's input is in
 * range of integer or not.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int check_bit(int num, int bit);

char * itobs(int n, char * ps);
void show_bstr(const char * str);

/* check that the user's input is valid */
int int_valid(const char * s);

int main(void)
{
    char num_str[20];
    int num, bit;
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    printf("Enter an integer (-2147483648 ~ 2147483647):\n");
    while (scanf("%s", num_str) != 1 || int_valid(num_str) != 1)
        printf("Error, try again.\n");

    printf("Enter which bit you want to check (1~32):\n");
    while (scanf("%d", &bit) != 1 || bit < 1 || bit > 32)
        printf("Error, try again.\n");

    num = atoi(num_str);
    itobs(num, bin_str);

    printf("The binary form of %d is\n", num);
    show_bstr(bin_str);

    if (check_bit(num, bit))
        printf("\nThe %d bit of above binary form is 1.\n", bit);
    else
        printf("\nThe %d bit of above binary form is 0.\n", bit);

    return 0;
}

int check_bit(int num, int bit)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    itobs(num, bin_str);

    return (bin_str[CHAR_BIT * sizeof(int) - bit] == '1') ? 1 : 0;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01&n) + '0';
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

/* Source from https://stackoverflow.com/questions/32600232/how-to-verify-that-user-input-number-is-in-fact-a-valid-unsigned-int-in-c */
// 0: invalid, 1: valid
int int_valid(const char * s)
{
    errno = 0;
    char * endptr;
    long long ll = strtoll(s, &endptr, 0);

    if (*endptr) return 0;

    if (errno) return 0;

    // Does 'll` value exceeds `integer` range?
    if (ll > INT_MAX || ll < INT_MIN) return 0;

    return 1;
}
