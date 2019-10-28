/* 
 * Modified from example 14.2 manybook.c
 * The user needs to enter the books that wants to orders.
 * Each order including the name and value of that book.
 */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL  40
#define MAXBKS  100              /* maximum number of books  */

struct book {                    /* set up book template     */
    char title[MAXTITL];
    float value;
};

int main(void)
{
    struct book orders[MAXBKS];  /* array of book order      */
    int count = 0;
    int index;

    printf("Enter the books you want to order.\n");
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(orders[count].title, MAXTITL) != NULL
           && orders[count].title[0] != '\0')
    {
        printf("Now enter the value.\n");
        scanf("%f", &orders[count++].value);
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your book orders:\n");
        for (index = 0; index < count; index++)
            printf("%s: $%.2f\n", orders[index].title, orders[index].value);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
