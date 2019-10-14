#include <stdio.h>

void s(void);

int main(void)
{
    s();
    s();
    s();
    printf("\n");

    s();
    s();
    printf("\n");

    s();
    printf("\n");
}

void s(void)
{
    printf("Smile!");
}
