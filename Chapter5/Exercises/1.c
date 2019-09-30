#define MIN_PER_HOUR 60
#include <stdio.h>
int main(void)
{
    int minutes;
    int hours;
    int left;

    printf("Please enter the minutes: ");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        hours = minutes / MIN_PER_HOUR;
        left = minutes % MIN_PER_HOUR;
        printf("%d minutes is %d hours and %d minutes.\n", minutes, hours, left);
        printf("Please enter the minutes: ");
        scanf("%d", &minutes);
    }
    printf("End!!!\n");

    return 0;
}
