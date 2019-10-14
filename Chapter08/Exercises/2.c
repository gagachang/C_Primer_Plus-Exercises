/*
 * Input a character
 * Output the ASCII code of the character
 * If it is control character, output Ctrl- 
 */
#include <stdio.h>
int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        printf("ASCII %d, ", ch);
        if (ch < ' ')
        {
            switch (ch)
            {
                case  0 : printf("Ctrl-@");
                          break;
                case  1 : printf("Ctrl-A");
                          break;
                case  2 : printf("Ctrl-B");
                          break;
                case  3 : printf("Ctrl-C");
                          break;
                case  4 : printf("Ctrl-D");
                          break;
                case  5 : printf("Ctrl-E");
                          break;
                case  6 : printf("Ctrl-F");
                          break;
                case  7 : printf("\a");
                          break;
                case  8 : printf("\b");
                          break;
                case  9 : printf("\t");
                          break;
                case 10 : printf("\n");
                          break;
                case 11 : printf("Ctrl-K");
                          break;
                case 12 : printf("\f");
                          break;
                case 13 : printf("\r");
                          break;
                case 14 : printf("Ctrl-N");
                          break;
                case 15 : printf("Ctrl-O");
                          break;
                case 16 : printf("Ctrl-P");
                          break;
                case 17 : printf("Ctrl-Q");
                          break;
                case 18 : printf("Ctrl-R");
                          break;
                case 19 : printf("Ctrl-S");
                          break;
                case 20 : printf("Ctrl-T");
                          break;
                case 21 : printf("Ctrl-U");
                          break;
                case 22 : printf("Ctrl-V");
                          break;
                case 23 : printf("Ctrl-W");
                          break;
                case 24 : printf("Ctrl-X");
                          break;
                case 25 : printf("Ctrl-Y");
                          break;
                case 26 : printf("Ctrl-Z");
                          break;
                case 27 : printf("Ctrl-[");
                          break;
                case 28 : printf("Ctrl-\\");
                          break;
                case 29 : printf("Ctrl-]");
                          break;
                case 30 : printf("Ctrl-^");
                          break;
                case 31 : printf("Ctrl--");
                          break;
            }
        }
        else
            putchar(ch);

        printf("\n");
    }

    return 0;
}
