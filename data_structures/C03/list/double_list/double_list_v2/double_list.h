/*************************************************************************
	> File Name: double_list.h
	> Author: daijinwei
	> Mail:   daijinwei41@gmail.com
	> Created Time: 2015年03月05日 星期四 21时21分00秒
 ************************************************************************/

#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <stdlib.h>

struct Node;
typedef struct Node *PNode;
typedef PNode Position;
typedef int Item;

struct Node{
    Item item;
    struct Node *pre;
    struct Node *next;
};

typedef struct{
    PNode head;
    PNode tail;
    int   size;
}DList; 

/* Assign the element */
Position dlist_make_node(Item item);

/* Free a Node that plist pointe */
Position dlist_free_node(PNode plist);

/* Get a list head*/
Position dlist_get_head(DList *dlist);

/* Get a list tail*/
Position dlist_get_tail(DList *dlist);

/* Get a list head*/
bool dlist_is_head(DList *dlist, Position p);

/* Get a list tail*/
bool dlist_is_tail(DList *dlist, Position P);

/* Get the list size*/
int dlist_get_size(DList *plist);

/* return true if the list is emtpy */
bool dlist_is_empty(DList dlist);

/* Init a empty list */
DList *dlist_init(); 

/* Insert a node before position p to dilst*/
Position dlist_insert_first(DList *plist, Position pnode);

/* Insert a node after positon pto dilst*/
Position dlist_insert_last(DList *dlist, Position pnode);

/* Insert a node after positon pto dilst*/
Position dlist_insert(DList *dlist, Position pnode, PNode s);

/* Create a dlist*/
void dlist_create_from_head(DList* dlist, Item array[], int n);

/* Create a dlist*/
void dlist_create_from_tail(DList* dlist, Item array[], int n);

/* Get the pnode previos */
Position dlist_get_previos(DList *dlist, PNode *pnode);

/* Get the pnode pre next */
Position dlist_get_next(DList *dlist, PNode *pnode);

/* Find a node in double_list */
Position dlist_find(DList *dlist, Item item);

/* Delete a exist item in dlist */
void dlist_delete(DList *dlist, Item item);

/* Clear a list */
void dlist_clear(DList *dlist);

/* Destroy a list */
void dlist_destroy(DList *dlist);

/* print the item in dlist */
void dlist_print(DList *dlist);

#endif
