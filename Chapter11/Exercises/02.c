/*
 * Implement a function that it will read n
 * input characters, or stopping at ' ', '\t' or '\n'.
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

        /* Breaking point */
        if (*temp == ' ' || *temp == '\t' || *temp == '\n')
        {
            printf("Get the special character, break.\n");
            break;
        }

        count++;
        temp++;
    }

    /* Set the last character to null */
    str[count] = '\0';
}
