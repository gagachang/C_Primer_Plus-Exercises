/*
 * Implements atoi() function in C "stdlib.h"
 * May use some functions in "ctype.h"
 *
 * If the input is not the string typr of a number, return 0.
 * Else return the integer type of that number.
 *
 * Utilize s_gets() function in the book to get the user's input.
 */
#include <stdio.h>
#include <ctype.h>
#define STR_SIZE 11

int implement_atoi(char * str);
char * s_gets(char * str, int n);

int main(void)
{
    char str[STR_SIZE];
    int result;

    puts("This program will implement atoi() function.");
    puts("Input a string, the function will return 0 if it is not a number.");
    puts("Otherwise return that number (up to 10 characters, or press enter now to quit):");

    while (s_gets(str, STR_SIZE) && str[0] != '\0')
    {
        result = implement_atoi(str);
        if (result)
            printf("The input string \"%s\" is equals to integer %d\n", str, result);
        else
            printf("The input string \"%s\" is not a number.\n", str);

        puts("\nInput another string (up to 10 characters, or press enter now to quit):");
    }
    puts("Bye!!!");

    return 0;
}

int implement_atoi(char * str)
{
    int result = 0;

    while (*str)
    {
        if (isdigit(*str) == 0)
            return 0;
        else
        {
            result = result * 10 + (*str - '0');
            str++;
        }
    }
    return result;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        if (str[i] == '\n')
            str[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
