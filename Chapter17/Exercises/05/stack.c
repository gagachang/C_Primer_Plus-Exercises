/* stack.c -- the Stack implementation  */
/* Referenced from example 17.7 queue.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* local functions */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeStack(Stack * s)
{
    s->top = NULL;
    s->items = 0;
}

bool StackIsFull(const Stack * s)
{
    return s->items == MAXSTACK;
}

bool StackIsEmpty(const Stack * s)
{
    return s->items == 0;
}

int StackItemCount(const Stack * s)
{
    return s->items;
}

bool Push(Item item, Stack * s)
{
    Node * pnew;

    if (StackIsFull(s))
        return false;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (StackIsEmpty(s))
        pnew->prev = NULL;
    else
    {
        s->top->next = pnew;
        pnew->prev = s->top;
    }
    s->top = pnew;
    s->items++;

    return true;
}

bool Pop(Item * pitem, Stack * s)
{
    Node * pt;

    if (StackIsEmpty(s))
        return false;

    CopyToItem(s->top, pitem);
    pt = s->top;
    s->top = s->top->prev;
    free(pt);
    s->items--;
    if (s->items == 0)
        s->top = NULL;

    return true;
}

/* empty the stack */
void EmptyTheStack(Stack * s)
{
    Item dummy;
    while (!StackIsEmpty(s))
        Pop(&dummy, s);
}

/* local functions */
static void CopyToNode(Item item, Node * pn)
{
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}
