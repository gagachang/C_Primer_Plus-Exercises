/*
 * Implement a function that it will reverse the string.
 * Utilize s_gets() function in the book to delete '\n' at the end of each input.
 *
 * The string size is restricted to 30 characters + '\0'
 *
 * str_reverse() will return a pointer to reversed string into str[STR_SIZE].
 * We need to call strcpy() to copy the recersed string into str[STR_SIZE].
 */
#include <stdio.h>
#include <string.h>
#define STR_SIZE 31

char * str_reverse(char * str);
char * s_gets(char * str, int n);

int main(void)
{
    char str[STR_SIZE];

    printf("This program will reverse the string you input.\n");
    printf("Input a string (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str, STR_SIZE) && str[0] != '\0')
    {
        puts("Reverse the string...");
        strcpy(str, str_reverse(str));
        printf("The result after reversing is \"%s\"\n", str);

        printf("\nInput another string (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

char * str_reverse(char * str)
{
    char reverse[STR_SIZE];

    int i = 1;
    while (i <= strlen(str))
    {
        *(reverse + i - 1) = *(str + strlen(str) - i);
        i++;
    }
    *(reverse + strlen(str)) = '\0';

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
