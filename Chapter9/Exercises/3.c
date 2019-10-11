/*
 * Let the user input a character
 * And the row and col
 * The character will be output row * col times
 */
#include <stdio.h>

void output(char ch, int row, int col);

int main(void)
{
    char ch;
    int row, col;

    printf("Enter a character you want to output: ");
    ch = getchar();
    while (getchar() != '\n')
        continue;

    printf("How many times you want the character output in a row? ");
    while (scanf("%d", &col) != 1)
    {
        scanf("%*s");
        printf("Please enter a number: ");
    }

    printf("How many rows you want the character output? ");
    while (scanf("%d", &row) != 1)
    {
        scanf("%*s");
        printf("Please enter a number: ");
    }

    output(ch, row, col);

    return 0;
}

void output(char ch, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            putchar(ch);
        putchar('\n');
    }
}
