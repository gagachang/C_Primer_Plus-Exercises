/* To input a character and print a pyramid
 * that the middle of buttom is that character.
 * Ex: input 'E', then print:
 *     A
 *    ABA
 *   ABCBA
 *  ABCDCBA
 * ABCDEDCBA
 */
#include <stdio.h>
int main(void)
{
    char target;

    printf("Please enter a character: ");
    scanf("%c", &target);

    for (int i = 0; i <= target - 'A'; i++) {
        char temp = 'A';

        for (int j = i; j < target - 'A'; j++)
            printf(" ");
        
        for ( ; temp <= 'A' + i; temp++)
            printf("%c", temp);

        for ( temp -= 2; temp >= 'A'; temp--)
            printf("%c", temp);

        for (int j = i; j < target - 'A'; j++)
            printf(" ");

        printf("\n");
    }

    return 0;
}
