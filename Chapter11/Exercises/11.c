/*
 * This program will accept at most ten strings.
 * Each string is at most 30 characters.
 * Then show the following options to user:
 * (a) Print the strings sequentially
 * (b) Print the strings according to ASCII code (low to high)
 * (c) Print the strings according to length (short to long)
 * (d) Print the strings according to length of the first word (short to long)
 * (e) Quit
 *
 * Utilize s_gets() and stsrt() functions in this book.
 */
#include <stdio.h>
#include <string.h>
#define LIM 10
#define STR_SIZE 31

void string_sort_ASCII(char * strings[], int num);
void string_sort_length(char * strings[], int num);
void string_sort_length_firstword(char * strings[], int num);
void print_strings(char * strings[], int num);
char * s_gets(char * str, int n);

int main(void)
{
    char input[LIM][STR_SIZE];
    char * strings[STR_SIZE];
    char choice;
    int i = 0, loop = 1;

    printf("Input the strings (up to ten strings or input EOF to end):\n");
    printf("Each string is at most 30 characters.\n");

    while (i < LIM && s_gets(input[i], STR_SIZE))
    {
        strings[i] = input[i];
        i++;
    }

    while (loop)
    {
        puts("\n******************** Choose an option ********************");
        puts("a) Print the strings sequentially");
        puts("b) Print the strings according to ASCII code (low to high)");
        puts("c) Print the strings according to length (short to long)");
        puts("d) Print the strings according to length of the first word (short to long)");
        puts("e) Quit");
        while (scanf("%c", &choice))
        {
            while (getchar() != '\n')
                continue;
            if (choice < 'a' || choice > 'e')
                printf("You need to input only a-e, please retry it.\n");
            else
                break;
        }

        switch(choice)
        {
            case 'a' :  puts("Print the strings sequentially:");
                        print_strings(strings, i);
                        break;
            case 'b' :  string_sort_ASCII(strings, i);
                        puts("Print the strings according to ASCII code (low to high):");
                        print_strings(strings, i);
                        break;
            case 'c' :  string_sort_length(strings, i);
                        puts("Print the strings according to length (short to long):");
                        print_strings(strings, i);
                        break;
            case 'd' :  string_sort_length_firstword(strings, i);
                        puts("Print the strings according to length of the first word (short to long)");
                        print_strings(strings, i);
                        break;
            case 'e' :  loop = 0;
                        break;
        }
    }
    puts("Bye!!!");

    return 0;
}

void string_sort_ASCII(char * strings[], int num)
{
    char * temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void string_sort_length(char * strings[], int num)
{
    char * temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strlen(strings[top]) > strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void string_sort_length_firstword(char * strings[], int num)
{
    char * temp;
    int top, seek;
    int length;
    int length_firstword[num];

    for (int k = 0; k < num; k++)
    {
        length = 0;
        while (strings[k][length] != ' ' && strings[k][length] != '\0' && strings[k] != "")
            length++;
        length_firstword[k] = length;
    }

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (length_firstword[top] > length_firstword[seek])
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void print_strings(char * strings[], int num)
{
    for (int i = 0; i < num; i++)
        puts(strings[i]);
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
    }
    return ret_val;
}
