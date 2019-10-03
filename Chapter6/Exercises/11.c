/* Input eight integers into an array
 * Ouput the elements of array reversely
 */
#include <stdio.h>
int main(void)
{
    int arr[8];

    for (int i = 0; i < 8; i++)
        scanf("%d", &arr[i]);

    for (int i = 7; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
