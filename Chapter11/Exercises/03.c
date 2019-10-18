/*
 * Design a function that read the first word of a input line.
 * Put it into a char array and delete all the other lines.
 * This word could not include ' ', '\t', '\n'
 */
#include <stdio.h>
#define SIZE 30
char * get_word(char * str);

int main(void)
{
    char str[SIZE];

    get_word(str);

    printf("The first word of input is: %s\n", str);

    return 0;
}

char * get_word(char * str)
{
    char * ret_val;
    int i = 0;

    fgets(str, SIZE, stdin);
    if (ret_val)
    {
        while ( str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
            i++;
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            str[i] = '\0';
        else
            while (getchar() != EOF)
                continue;
    }
    return ret_val;
}
