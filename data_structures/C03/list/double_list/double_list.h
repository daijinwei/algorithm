/*************************************************************************
	> File Name: double_list.h
	> Author: daijinwei
	> Mail:   daijinwei41@gmail.com
	> Created Time: 2013年03月05日 星期四 21时21分00秒
 ************************************************************************/

#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <stdlib>

struct Node;
typedef struct Node *PNode;
typedef PNode Position, Dlist;
typedef int Item;

struct Node{
    Item item;
    struct Node *pre;
    struct Node *next;
};

/* Assign the element */
Position dlist_make_node(Item i);

/* Free a Node that plist pointe */
Position dlist_free_node(PNode plist);

/* return true if the list is emtpy */
bool dlist_is_empty(Dlist dlist);

/* Init a empty list */
Dlist dlist_init(); 

/* Create a dlist*/
void dlist_create(Dlist dlist, Item array[], int n);

/* Destroy a list */
void dlist_destroy(Dlist plist);

/* Clear a list */
void dlist_clear(Dlist *plist);

/* Get a list head*/
Position dlist_get_head(Dlist *plist);

/* Get a list tail*/
Position dlist_get_tail(Dlist *plist);

/* Get the list size*/
int dlist_get_size(Dlist *plist);

/* Get the pnode previos */
Position dlist_get_previos(Dlist *plist, PNode *pnode);

/* Get the pnode pre next */
Position dlist_get_next(Dlist *plist, PNode *pnode);

/* Insert a node before position p to dilst*/
void dlist_insert_before(Dlist *plist, Position p);

/* Insert a node after positon pto dilst*/
void dlist_insert_after(Dlist *plist, Position p);

#endif
