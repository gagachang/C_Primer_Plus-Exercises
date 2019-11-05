/*
 * This program is used to test the Stack interface
 * Must be compiled with stack.c
 *
 * This program will let the user input a string,
 * and push the characters of string into stack sequentially.
 * Finally, pop all the characters from the stack and print them.
 * The string will be print reversely because of effect of stack.
 */
#include <stdio.h>
#include <string.h>
#include "stack.h"
#define MAXSIZE 19

char * s_gets(char * str, int n);

int main(void)
{
    Stack stack;
    Item temp;
    char ch;
    char s[MAXSIZE];

    InitializeStack(&stack);
    puts("Testing the Stack interface. Type a to enter a string,");
    puts("type p to pop the string, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        while (getchar() != '\n')
            continue;

        if (ch != 'a' && ch != 'p')
            continue;

        if (ch == 'a')
        {
            puts("Enter a string to push into stack: ");
            s_gets(s, MAXSTACK);
    
            int index = 0;
            while (s[index])
            {
                if (!StackIsFull(&stack))
                {
                    temp = s[index];
                    Push(temp, &stack);
                }
                else
                    puts("Stack is full!");

                index++;
            }
        }
        else
        {
            if (StackIsEmpty(&stack))
                puts("Nothing to pop!");
            else
            {
                puts("Pop the string from stack:");
                while (!StackIsEmpty(&stack))
                {
                    Pop(&temp, &stack);
                    printf("%c", temp);
                }
                puts("");
            }
        }
        puts("\nType a to enter a string, p to pop, q to quit:");
    }
    EmptyTheStack(&stack);
    puts("Bye!");

    return 0;
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
