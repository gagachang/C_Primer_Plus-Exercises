/* Enter a word into a char array
 * Use a for loop to output it reversely
 * */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[30];

    printf("Please enter a word (up to 29 characters): ");
    scanf("%s", word);

    for (int i = strlen(word); i >= 0; i--)
        printf("%c", *(word + i));

    printf("\n");

    return 0;
}
