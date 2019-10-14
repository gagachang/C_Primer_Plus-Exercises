/*
 * Design a function that
 * It will accept a character from main()
 * And return the location in alphabet list
 * if it is an alphabet.
 * Otherwise return -1 if it is not.
 */
#include <stdio.h>

int isAlphabet(char ch);

int main(void)
{
    char ch;

    printf("Enter a string, I will tell you whether each character is alphabet or not: ");
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
            continue;

        if(isAlphabet(ch) != -1)
        {
            printf("Yes, %c is an alphabet.\n", ch);
            printf("And its location in alphabet list is %d.\n", isAlphabet(ch));
        }
        else
            printf("No, %c is not an alphabet.\n", ch);
    }
    printf("Done.\n");

    return 0;
}

int isAlphabet(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return (ch - 'a') + 1;
    else if (ch >= 'A' && ch <= 'Z')
        return (ch - 'A') + 1;
    else
        return -1;
}
