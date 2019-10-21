/* 
 * Modified from example 12.4 global.c
 * In this exercise, we can't use global variable.
 * We need to use a pointer to the variable.
 */
#include <stdio.h>
void critic(int * ptr_units);
int main(void)
{
    int units;

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int * ptr_units)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", ptr_units);
}
