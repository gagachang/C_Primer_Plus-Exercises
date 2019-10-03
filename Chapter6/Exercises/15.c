/* Input a line of data into an char array[255]
 * Output it reversely
 */
#include <stdio.h>
int main(void)
{
    char arr[255];
    int index = -1;

    do
    {
        index++;
        scanf("%c", &arr[index]);
    } while (arr[index] != '\n');

    for (int i = --index; i >= 0; i--)
        printf("%c", arr[i]);

    printf("\n");

    return 0;
}
