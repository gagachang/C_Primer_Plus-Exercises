/* stack.h -- interface for a stack     */
/* Referenced from example 17.6 queue.h */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

/* Item type for stack here */
typedef char Item;

#define MAXSTACK 20

/* Use doubly linked list to implement stack */
typedef struct node
{
    Item item;
    struct node * prev;
    struct node * next;
} Node;

typedef struct stack
{ 
    Node * top;  /* pointer to the top of stack */
    int items;   /* number of items in stack    */
} Stack;

/* All the stack-related functions */
void InitializeStack(Stack * s);

bool StackIsFull(const Stack * s);

bool StackIsEmpty(const Stack * s);

int StackItemCount(const Stack * s);

bool Push(Item item, Stack * s);

bool Pop(Item * pitem, Stack * s);

void EmptyTheStack(Stack * s);

#endif
