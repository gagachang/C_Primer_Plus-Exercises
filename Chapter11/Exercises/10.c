/*
 * Implement a function that it will delete all the ' ' of the string.
 * Utilize s_gets() function in the book to delete '\n' at the end of each input.
 *
 * The string size is restricted to 30 characters + '\0'
 */
#include <stdio.h>
#include <string.h>
#define STR_SIZE 31

char * delete_space(char * str);
char * s_gets(char * str, int n);

int main(void)
{
    char str[STR_SIZE];

    printf("This program will delete all the ' ' of the string you input.\n");
    printf("Input a string (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str, STR_SIZE) && str[0] != '\0')
    {
        puts("Delete all the ' ' of the string...");
        strcpy(str, delete_space(str));
        printf("The result after deletion is \"%s\"\n", str);

        printf("\nInput another string (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

char * delete_space(char * str)
{
    char reverse[STR_SIZE];

    int i = 0;
    while (*str)
    {
        if (*str == ' ')
            str++;
        else
        {
            reverse[i++] = *str;
            str++;
        }
    }
    reverse[i] = '\0';
    str = reverse;

    return str;
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
