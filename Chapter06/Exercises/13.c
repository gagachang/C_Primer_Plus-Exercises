/* Create an array to store the exponential of 2
 * from 0 to 8
 */
#include <stdio.h>
int main(void)
{
    int arr[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 8; i++) {
        for (int expo = 0; expo < i; expo++)
            arr[i] *= 2;
    }

    int index = 0;
    do
    {
        printf("%d ", arr[index]);
    } while (++index < 8);

    printf("\n");

    return 0;
}
