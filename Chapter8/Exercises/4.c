/*
 * Input the standard input
 * Calculate how many letters and words
 * Ouput that how many letters in a word on average
 */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int ch;
    int words = 0;
    int letters = 0;

    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ' || ispunct(ch))
            words++;
        else
            letters++;
    }

    /* except the null terminator */
    printf("There are %d letters in %d words on average.\n", --letters / ++words, words);

    return 0;
}
