/* list.c --functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
/* We don't need this because we won't use dynamically allocated memory here */
// static void CopyToNode(Item item, Node * pnode);

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    (*plist).items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if ((*plist).items == 0)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    bool full;

    if ((*plist).items == MAXSIZE)
        full = true;
    else
        full = false;

    return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return (*plist).items;
}

/* Puts item into the end of entries of List */
bool AddItem(Item item, List * plist)
{
    (*plist).entries[(*plist).items] = item;
    (*plist).items++;

    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    for (int i = 0; i < (*plist).items; i++)
        (* pfun)((*plist).entries[i]); /* apply function to item */
}

/* We don't need this function because we didn't use */
/* dynamically allocated memory ( malloc() )         */
void EmptyTheList(List * plist)
{

}

/* We don't need this function either */
// static void CopyToNode(Item item, Node * pnode)
// {

// }
