#include <stdio.h>
#include <string.h>
int main(void)
{
    char firstName[30];
    char lastName[30];

    printf("Please enter your first name, and last name: \n");
    scanf("%s %s", firstName, lastName);

    printf("%s %s\n", firstName, lastName);
    printf("%*ld %*ld\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));
    printf("%s %s\n", firstName, lastName);
    printf("%-*ld %-*ld\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));

    return 0;
}
