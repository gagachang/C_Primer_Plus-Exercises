/*
 * Implement a function "is_within(char target, char * str)".
 * If the target character is within string str, return non-zero value
 * else return zero.
 *
 * Use a loop to test user's input.
 * Utilize s_gets() function in the book to delete '\n' at the end of string.
 */
#include <stdio.h>
#define SIZE 31

char * s_gets(char * st, int n);
int is_within(char target, char * str);

int main(void)
{
    char target;
    char str[SIZE];
    int result = 0;

    printf("Input a string (up to 30 characters, or press enter now to quit):\n");
    while (s_gets(str, SIZE) && str[0] != '\0')
    {
        printf("Enter a character you want to find in this string:\n");
        target = getchar();
        while (getchar() != '\n')
            continue;

        result = is_within(target, str);
        if (result)
            printf("The \'%c\' is within \"%s\"\n", target, str);
        else
            printf("The \'%c\' is not within \"%s\"\n", target, str);

        printf("\nInput another string (up to 30 characters, or press enter now to quit):\n");
    }
    puts("Bye!");

    return 0;
}

int is_within(char target, char * str)
{
    while (*str)
    {
        if (*str == target)
            return 1;
        str++;
    }
    return 0;
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
