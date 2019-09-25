#include <stdio.h>
int main(void)
{
    int age_year, age_day;
 
    printf("Please input your age of year: ");
    scanf("%d", &age_year);
    printf("Your age is %d years old and %d days old.\n", age_year, age_year * 365);

    return 0;
}
