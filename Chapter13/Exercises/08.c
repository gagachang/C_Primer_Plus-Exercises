/*
 * This program will count the number of target character in
 * stdin or some designated files, and print the result in 
 * terminal.
 *
 * Here we need some command line arguments:
 * 1. A target character want to find.
 * 2. (Optional) Name of files.
 *
 * If there is no 2. arguments, let the user input a string.
 *
 * For example, "./08 a 08_input" will find how many 'a' in 08_input.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUTSIZE 21

void UserInput(char **argv);
void Files(int argc, char **argv);
char * s_gets(char * str, int n);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s character files(optional)\n", argv[0]);
        exit(1);
    }

    if (argc == 2)
        UserInput(argv);
    else
        Files(argc, argv);

    return 0;
}

void UserInput(char **argv)
{
    char target = argv[1][0];   // target character to find
    int count = 0;              // counter
    char input[INPUTSIZE];      // user input string

    puts("Enter a string (up to 20 characters):");
    s_gets(input, INPUTSIZE);

    for (int i = 0; i < strlen(input); i++)
        if ( *(input + i) == target)
            count++;

    printf("There are %d \'%c\' in %s.\n", count, target, input);
}

void Files(int argc, char **argv)
{
    FILE * fp;
    int file_count = 0;
    char target = argv[1][0];   // target character to find
    int count = 0;              // counter
    char ch;

    while (file_count < argc - 2)
    {
        if ((fp = fopen(argv[file_count + 2], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[file_count + 2]);
            exit(1);
        }
        while ((ch = getc(fp)) != EOF)
            if (ch == target)
                count++;

        printf("There are %d \'%c\' in file %s.\n", count, target, argv[file_count + 2]);

        fclose(fp);
        count = 0;
        file_count++;
    }
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
