/*
 * Implement a function that it will read n
 * input characters, including ' ', '\t', '\n'.
 * 
 * In order to test it, this program will
 * (1) Replace ' '  with '!'
 * (2) Replace '\t' with '@'
 * (3) Replace '\n' with '#'
 */
#include <stdio.h>
#include <string.h>
#define N 20    // Set N to 20
void get_input(char * str, int n);
int main(void)
{
    char str[N + 1];

    get_input(str, N);

    puts("The input string is:");
    puts(str);

    return 0;
}

void get_input(char * str, int n)
{
    int count = 0;
    char * temp = str;

    while (count < n)
    {
        *temp = getchar();

        /* Replace some special characters to test */
        if (*temp == ' ')
            *temp = '!';
        if (*temp == '\t')
            *temp = '@';
        if (*temp == '\n')
            *temp = '#';

        count++;
        temp++;
    }

    /* Set the last character to null */
    str[n] = '\0';
}
