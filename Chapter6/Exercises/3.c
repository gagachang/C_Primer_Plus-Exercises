/* To print:
 * F
 * FE
 * FED
 * FEDC
 * FEDCB
 * FEDCBA
 */
#include <stdio.h>
int main(void)
{
    char ch = 'F';

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++)
            printf("%c", ch - j);
        printf("\n");
    }

    return 0;
}
