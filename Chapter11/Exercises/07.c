/*
 * Implement a function "strncpy()" in C library
 * Utilize s_gets() function in the book to delete '\n' at the end of each input.
 *
 * The str2 is restricted to 30 characters + '\0'
 * The str1 is restricted to 10 characters + '\0'
 */
#include <stdio.h>
#define STR1_SIZE 10
#define STR2_SIZE 31
#define COPY_SIZE 10

void implement_strncpy(char * str1, char * str2, int n);
char * s_gets(char * str, int n);

int main(void)
{
    char str1[STR1_SIZE];
    char str2[STR2_SIZE];

    printf("This program will copy first ten characters of str2 into str1...\n");
    printf("Input a string you want to copy (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str2, STR2_SIZE) && str2[0] != '\0')
    {
        puts("Copy the string into str1...");
        implement_strncpy(str1, str2, COPY_SIZE);
        printf("The str1 is \"%s\"", str1);

        printf("\nInput another string you want to copy (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

void implement_strncpy(char * str1, char * str2, int n)
{
    int index = 0;

    while (str2[index] != '\0' && index < n)
    {
        str1[index] = str2[index];
        index++;
    }
    str1[index] = '\0';
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
