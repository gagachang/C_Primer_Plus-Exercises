/* Create two arrays
 * The elements of first array is entered bt user
 * The elements of second array is calculate the
 * accumulated elements from the first array.
 * For eample: arr2[2] = arr1[0] + arr1[1] + arr1[2].
 */
#include <stdio.h>
int main(void)
{
    double arr1[8];
    double arr2[8];

    for (int i = 0; i < 8; i++) {
        scanf("%lf", &arr1[i]);
        arr2[i] = (i==0 ? arr1[i] : arr2[i-1] + arr1[i]);
    }

    for (int i = 0; i < 8; i++)
        printf("%lf ", arr1[i]);

    printf("\n");

    for (int i = 0; i < 8; i++)
        printf("%lf ", arr2[i]);

    printf("\n");

    return 0;
}
