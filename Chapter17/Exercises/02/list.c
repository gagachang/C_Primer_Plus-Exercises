/* list.c --functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node * pnode);

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist == NULL)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode;
        
   if (plist != NULL)
       pnode = plist->head;         /* set to start of list */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;        /* set to next node     */
    }

    return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (use Node * end)       */
bool AddItem(Item item, List * plist)
{
    Node * pnew;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;       /* quit function on failure */

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (plist->head == NULL)         /* empty list, so place pnew */
    {                                /* at head and end of list   */
        plist->head = pnew;
        plist->end = pnew;
    }
    else
    {
        plist->end->next = pnew;     /* attach the new node */
        plist->end = pnew;           /* set the end of list */
    }
    return true;
}

/* visit each node and execute function pointed ti by pfun */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode;                      /* set to start of list   */

    if (plist != NULL)
        pnode = plist->head;

    while (pnode != NULL)
    {
        (* pfun)(pnode->item);         /* apply function to item */
        pnode = pnode->next;           /* advance to next item   */
    }
}

/* free memory allocated bt malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List * plist)
{
    Node * psave, * current;

    if (plist != NULL)
        current = plist->head;

    while (current != NULL)
    {
        psave = current->next;  /* save address of next node */
        free(current);          /* free current node         */
        current = psave;        /* advance to next node      */
    }
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;  /* structure copy */
}
