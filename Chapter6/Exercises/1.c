#include <stdio.h>
int main(void)
{
    char ch = 'a';
    char arr[26];

    for (int i = 0; i < 26; i++, ch++)
        arr[i] = ch;

    for (int i = 0; i < 26; i++)
        printf("%c ", arr[i]);

    printf("\n");
 
    return 0;
}
