/*
 * This program will accept two binary strings from command line arguments.
 * And perform the NOT, AND, OR, XOR operations on the two binary strings.
 *
 * We must check that if the input string is 32 bits and only contains 0 or 1.
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bitwise_operations(char * binary_str1, char * binary_str2);
void NOT(char * binary_str1, char * binary_str2);
void AND(char * target, char * binary_str1, char * binary_str2);
void OR(char * target, char * binary_str1, char * binary_str2);
void XOR(char * target, char * binary_str1, char * binary_str2);

bool check_binary_str(char * binary_str);
void show_bstr(const char * str);

int main(int argc, char ** argv)
{
    if (argc < 3)
    {
        printf("Usage: %s binary_str1 binary_str2\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[1]) != 32 || strlen(argv[2]) != 32)
    {
        puts("The binary string must be 32 bits, try again.");
        exit(1);
    }

    if (!check_binary_str(argv[1]) || !check_binary_str(argv[2]))
    {
        puts("This is not a binary string, try again.");
        exit(1);
    }

    printf("The first binary string:  ");
    show_bstr(argv[1]);

    printf("\nThe second binary string: ");
    show_bstr(argv[2]);

    bitwise_operations(argv[1], argv[2]);

    return 0;
}

void bitwise_operations(char * binary_str1, char * binary_str2)
{

    char str1[CHAR_BIT * sizeof(int) + 1];
    char str2[CHAR_BIT * sizeof(int) + 1];

    /* NOT */
    memcpy(str1, binary_str1, CHAR_BIT * sizeof(int) + 1);
    memcpy(str2, binary_str2, CHAR_BIT * sizeof(int) + 1);
    NOT(str1, str2);
    puts("\n\nAfter the NOT operation");
    printf("The first binary string:  ");
    show_bstr(str1);

    printf("\nThe second binary string: ");
    show_bstr(str2);

    /* AND */
    memset(str1, '0', CHAR_BIT * sizeof(int));
    AND(str1, binary_str1, binary_str2);
    puts("\n\nThe AND operation between two binary strings:");
    show_bstr(str1);

    /* OR */
    memset(str1, '0', CHAR_BIT * sizeof(int));
    OR(str1, binary_str1, binary_str2);
    puts("\n\nThe OR operation between two binary strings:");
    show_bstr(str1);

    /* XOR */
    memset(str1, '0', CHAR_BIT * sizeof(int));
    XOR(str1, binary_str1, binary_str2);
    puts("\n\nThe XOR operation between two binary strings:");
    show_bstr(str1);

    puts("");
}

void NOT(char * binary_str1, char * binary_str2)
{
    for (int i = 0; i < CHAR_BIT * sizeof(int); i++)
    {
        binary_str1[i] = !(binary_str1[i] - '0') + '0';
        binary_str2[i] = !(binary_str2[i] - '0') + '0';
    }
}

void AND(char * target, char * binary_str1, char * binary_str2)
{
    for (int i = 0; i < CHAR_BIT * sizeof(int); i++)
        target[i] = (binary_str1[i] - '0') & (binary_str2[i] - '0') ? '1' : '0';
}

void OR(char * target, char * binary_str1, char * binary_str2)
{
    for (int i = 0; i < CHAR_BIT * sizeof(int); i++)
        target[i] = (binary_str1[i] - '0') | (binary_str2[i] - '0') ? '1' : '0';
}

void XOR(char * target, char * binary_str1, char * binary_str2)
{
    for (int i = 0; i < CHAR_BIT * sizeof(int); i++)
        target[i] = (binary_str1[i] - '0') ^ (binary_str2[i] - '0') ? '1' : '0';
}

bool check_binary_str(char * binary_str)
{
    for (int i = 0; i < strlen(binary_str); i++)
        if (binary_str[i] != '0' && binary_str[i] != '1')
            return false;
    return true;
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
