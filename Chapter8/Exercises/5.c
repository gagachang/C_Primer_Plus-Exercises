/*
 * Let the computer guess a number we set.
 * Type 'y' if its guess is correct.
 * Type 'l' if the answer is lower than its guess.
 * Type 'h' if the answer is higher than its guess.
 * The computer will use binary search strategy to guess the answer.
 */
#include <stdio.h>
int main(void)
{
    int lower_bound = 0;
    int upper_bound = 100;
    int guess = 50;
    char response;

    printf("Pick an integer from %d to %d. I will try to guess ", lower_bound, upper_bound);
    printf("it.\nRespond with a y if my guess is right.\n");
    printf("Response a l if the answer is lower than my guess, ");
    printf("and a h if the answer if higher than my guess.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')      /* get response, compare to y */
    {
        if (response == 'l')
        {
            upper_bound = guess;
            guess = (lower_bound + upper_bound) / 2;
            printf("Well, then, is it %d?\n", guess);
        }
        else if (response == 'h')
        {
            lower_bound = guess;
            guess = (lower_bound + upper_bound) / 2;
            printf("Well, then, is it %d?\n", guess);
        }
        else
            printf("Sorry, I understand only y, l, or h.\n");

        while (getchar() != '\n')
            continue;
    }
    
    printf("I knew I could do it!\n");

    return 0;
}
