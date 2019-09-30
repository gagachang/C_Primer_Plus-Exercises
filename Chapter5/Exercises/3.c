#include <stdio.h>
int main(void)
{
    int days;
    int weeks;
    int left;

    printf("Please enter the days: ");
    scanf("%d", &days);
    
    while (days > 0)
    {
        weeks = days / 7;
        left = days % 7;
        printf("%d days are %d weeks, %d days.\n", days, weeks, left);
        printf("Please enter the days: ");
        scanf("%d", &days);
    }
    printf("End!!!\n");

    return 0;
}
