/*
 * Implement a function "strstr()" in C library
 * Utilize s_gets() function in the book to delete '\n' at the end of each input.
 *
 * The str1 is restricted to 30 characters + '\0'
 * The str2 is restricted to 10 characters + '\0'
 */
#include <stdio.h>
#define STR1_SIZE 31
#define STR2_SIZE 11

char * string_in(char * str1, char * str2);
char * s_gets(char * str, int n);

int main(void)
{
    char str1[STR1_SIZE];
    char str2[STR2_SIZE];
    char * start;

    printf("This program will find if str2 is including in str1\n");
    printf("If yes, return a pointer to the first character, otherwise return a NULL pointer\n");
    printf("Input a string (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str1, STR1_SIZE) && str1[0] != '\0')
    {
        puts("Input another string you want to find in str1:");
        s_gets(str2, STR2_SIZE);
        puts("Finding str2 in str1...");
        start = string_in(str1, str2);
        if (start)
            printf("The \"%s\" is in \"%s\"\n", str2, str1);
        else
            printf("The \"%s\" is not in \"%s\"\n", str2, str1);

        printf("\nInput another string (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

char * string_in(char * str1, char * str2)
{
    int i = 0, j = 0;
    char * start;
    char * temp_str2;

    while (str1[i])
    {
        if (str1[i] == str2[0])
        {
            start = &str1[i];
            temp_str2 = str2;
            j = i;
            while (str1[j] == *temp_str2)
            {
                j++;
                temp_str2++;
                if (*temp_str2 == '\0')
                    return start;
            }        
        }
        i++;
    }
    return NULL;
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
