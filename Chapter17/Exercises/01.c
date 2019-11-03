/* 
 * Modified example 17.2 firms2.c
 * Let the program can show list of movies
 * sequentially and conversely.
 *
 * There are two ways to reach the goal:
 * 1. Doubly Linked List
 * 2. Recurrence
 *
 * I will use doubly linked list here, and declare a pointer
 * to the tail of list.
 */
#include <stdio.h>
#include <stdlib.h>      /* has the malloc prototype      */
#include <string.h>      /* has the strcpy prototype      */
#define TSIZE    45      /* size of array to hold title   */

struct film {
    char title[TSIZE];
    int rating;
    struct film * prev;  /* points to previous struct in list */
    struct film * next;  /* points to next struct in list     */
};

char * s_gets(char * st, int n);

int main(void)
{
    struct film * head = NULL, * tail = NULL;
    struct film * prev, * current;
    char input[TSIZE];

/* Gather and store information          */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)       /* first structure       */
        {
            head = current;
            head->prev = NULL;
        }
        else                    /* subsequent structures */
        {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

/* Set the tail of the list               */
    tail = current;

/* Show list of movies sequentially       */
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list (sequentially):\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

/* Show list of movies conversely         */
    if (head == NULL)
        printf("\nNo data entered. ");
    else
        printf("\nHere is the movie list (conversly):\n");
    current = tail;
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title, current->rating);
        current = current->prev;
    }
/* Program done, so free allocated memory */
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("Bye!\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
