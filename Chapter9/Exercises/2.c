/*
 * Design a funciton chline(ch, i, j)
 * It will print character 'ch' from location i to j in a line.
 */
#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int begin, size;

    printf("Enter a character you want to input: ");
    scanf("%c", &ch);           // Only get the first character
    while (getchar() != '\n')
        continue;

    printf("Enter the beginning location of this character: ");
    scanf("%d", &begin);

    printf("Enter the size of the character you want to input: ");
    scanf("%d", &size);

    chline(ch, begin, size);

    return 0;
}

void chline(char ch, int i, int j)
{
    for (int k = 1; k < i; k++)
        putchar(' ');
    for (int k = i; k <= j; k++)
        putchar(ch);
    putchar('\n');
}
