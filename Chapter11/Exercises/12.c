/*
 * This program will count the following types of input characters:
 * (1) Characters
 * (2) Upper cases
 * (3) Lower cases
 * (4) Punctuations
 * (5) Digits
 *
 * Note: '\n' is not a type.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int char_number = 0;
    int upper_case = 0;
    int lower_case = 0;
    int punct_letter = 0;
    int digit_number = 0;

    puts("Input the characters: (EOF to quit)");

    while ((ch = getchar()) != EOF)
    {
        char_number++;

        if (ch == '\n')
            char_number--;

        if (isupper(ch))
            upper_case++;
        else if (islower(ch))
            lower_case++;
        else if (ispunct(ch))
            punct_letter++;
        else if (isdigit(ch))
            digit_number++;
    }

    printf("There are %d characters.\n",   char_number);
    printf("There are %d upper cases.\n",  upper_case);
    printf("There are %d lower cases.\n",  lower_case);
    printf("There are %d punctuations.\n", punct_letter);
    printf("There are %d digits.\n",       digit_number);

    return 0;
}
