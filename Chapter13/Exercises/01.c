/* 
 * Modified example 13.1 count.c
 * Request for user's input rather than using command line argument
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 21

char * s_gets(char * str, int n);

int main(void)
{
    int ch;
    char filename[NAME_SIZE];
    FILE *fp;
    unsigned long count = 0;

    printf("Enter the file name (up to 20 characters):\n");
    s_gets(filename, NAME_SIZE);
    
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

    return 0;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (ret_val)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
