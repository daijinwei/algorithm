/*************************************************************************
	> File Name: double_list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月05日 星期四 22时27分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "double_list.h"

Position dlist_make_node(Item item){
    Position node = NULL;
    node = (Position)malloc(sizeof(struct Node));
    if(!node){
        node->item = item;
        node->previos = NULL;
        node->next = NULL;
    }
    return node;
}

Position dlist_free_node(PNode plist){
    freela(plist);
} 

Position dlist_get_head(DList *dlist){
    return dlist->head;
}

Position dlist_get_tail(DList *dlist){
    return dlist->tail;
}

int dlist_get_size(DList *dlist){
    return dlist->size;
}

bool dlist_is_empty(DList *dlist){
    return (0 == dlist_get_size(dlist)) && (dlist->head == dlist->tail);
}   

DList *dlist_init(){
    DList *double_list = NULL;
    double_list = (DList *)malloc(sizeof(DLst));
    dlist_make_node(0); 
    if(!double_list){
        double_list->head = NULL;
        double_list->next = NULL;
        double_list->size = 0;
    }
    return double_list;
}

Position dlist_insert_first(DList *dlist, Position pnode){
    Position head = dlist_get_head(dlist); 
    if(dlist_is_empty(dlist)){
        dlist->tail = pnode;
    }
    ++(dlist->size);
    pnode->previous = head;
    pnode->next = head->next;
   
    if(head->next != NULL){
        head->next->previous = pnode;
    }
    head->next = pnode;
    return pnode;
}

Position dlist_insert_last(DList *dlist, Position pnode){
    Position last = NULL;
    last = dlist_get_tail(dlist);

    pnode->previous = last;
    pnode->next = NULL;

    dlist->tail = pnode;
    ++(dlist->size);

    last->next = pnode;  
    return pnode; 
}

void dlist_create_from_head(DList *dlist, Item array[], int num){
    int item_count;
    DList *dlist = dlist_init();
    for(item_count = 0; item_count < num; ++item_count){
        dlist_insert_first(dlist, dlist_make_node(array[item_count]));
    }
}


void dlist_create_from_tail(DList *dlist, Item array[], int num){
    int item_count;
    DList *dlist = dlist_init();
    for(item_count = 0; item_count < num; ++item_count){
        dlist_insert_last(dlist, dlist_make_node(array[item_count]));
    }
}

Position dlist_get_previos(DList *dlist, PNode *pnode){
    return pnode->previous;
}

Position dlist_get_next(DList *dlist, PNode *pnode){
    return pnode->next;
}

Position dlist_find(DList *dlist, Item item){
    Position head = dlist_get_head(dlist);
    Position tmp = head;
    
    if(tmp != NULL){
        while(tmp != NULL && tmp->next != item){
           tmp->next; 
        }
        return tmp
    }else{
        return NULL;
    }
}
