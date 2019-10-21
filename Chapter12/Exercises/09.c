/*
 * The program will ask user to input how many words he/she wants to input.
 * We must allocate enough memory to store strings and pointers to these strings.
 * Need to call malloc() to allocate the memory.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int count;
    char ch;
    char * temp;
    char ** words;

    printf("How many words do you wish to enter? ");
    scanf("%d", &count);

    /* clear the buffer */
    while (getchar() != '\n')
        continue;

    /* allocate memory and check it */
    words = (char **) malloc(count * sizeof(char *));
    if (!words)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    /* Ready to read the user's input words */
    printf("Enter %d words now:\n", count);
    for (int i = 0; i < count; i++)
    {
        int index = 0;

        /* allocate memory to store each string and check it */
        temp = malloc(30 * sizeof(char));
        if (!temp)
        {
            printf("Memory allocation failed.\n");
            return 0;
        }

        /* Start reading */
        while ((ch = getchar()) && ch != ' ' && ch != '\n')
        {
            *(temp + index) = ch;
            index++;
        }
        /* Null terminator of a string */
        *(temp + index) = '\0';

        /* assigned to words array */
        words[i] = temp;
    }

    printf("Here are your words:\n");
    for (int i = 0; i < count; i++)
        puts(words[i]);

    return 0;
}
