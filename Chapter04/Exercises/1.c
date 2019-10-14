#include <stdio.h>
int main(void)
{
    char firstName[30];     // We need to allocate the space to it.
    char lastName[30];

    printf("Please input your first name: ");
    scanf("%s", firstName);
    printf("Please input your last name: ");
    scanf("%s", lastName);

    printf("Your last name is %s.\n", lastName);
    printf("And your first name is %s.\n", firstName);

    return 0;
}
