#include <stdio.h>
int main(void)
{
    char name[10];
    int name_length;

    printf("Please enter your name: ");
    scanf("%s", name);

    name_length = strlen(name);

    printf("Your name is \"%s\".\n", name);
    printf("Your name is \"%20s\".\n", name);
    printf("Your name is \"%-20s\".\n", name);
    printf("Your name is \"%*s\".\n", name_length + 3, name);

    return 0;
}
