/*
 * Implement a C library function "strchr()".
 * Use a loop to test it according to user input.
 *
 * Utilize s_gets() function in the book to delete the '\n' at the end of each input.
 */
#include <stdio.h>
#define SIZE 31

char * implement_strchr(char * str, char target);
char * s_gets(char * str, int n);

int main(void)
{
    char str[SIZE];
    char target;
    char * result;

    printf("Input a string (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str, SIZE) && str[0] != '\0')
    {
        printf("Enter a character you want to search in this string:\n");
        target = getchar();
        while (getchar() != '\n')
            continue;

        result = implement_strchr(str, target);
        if (result)
        {
            printf("The string starting at this character is:\n");
            puts(result);
        }
        else
            puts("Searching failed.");

        printf("\nInput another string (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

char * implement_strchr(char * str, char target)
{
    while (*str)
    {
        if (*str == target)
            return str;
        str++;
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
