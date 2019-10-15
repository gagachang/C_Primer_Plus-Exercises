#include <stdio.h>
int main(void)
{
    float height;
    char name[30];

    printf("Please enter your height(inches) and name: ");
    scanf("%f %s", &height, name);

    printf("%s, you are %.3f feet tall.\n", name, height / 12);

    return 0;
}
