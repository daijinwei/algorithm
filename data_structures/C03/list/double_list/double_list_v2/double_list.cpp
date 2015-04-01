/*************************************************************************
	> File Name: double_list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2013年03月05日 星期四 22时27分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "double_list.h"

Position dlist_make_node(Item item){
    Position node = NULL;
    node = (Position)malloc(sizeof(struct Node));
    if(NULL != node){
        node->item = item;
        node->pre = NULL;
        node->next = NULL;
    }
    return node;
}

void dlist_free_node(PNode plist)
{
    free(plist);
    plist = NULL;
} 

Position dlist_get_head(DList *dlist){
    return dlist->head;
}

Position dlist_get_tail(DList *dlist){
    return dlist->tail;
}

bool dlist_is_head(DList *dlist, Position p){
    return dlist_get_head(dlist)->pre == NULL;
}

bool dlist_is_tail(DList *dlist, Position p){
    return p->next == NULL;
}

int dlist_get_size(DList *dlist){
    return dlist->size;
}

bool dlist_is_empty(DList *dlist){
    return (0 == dlist_get_size(dlist)) && (dlist->head == dlist->tail);
}   

DList *dlist_init(){
    DList *double_list = NULL;
    double_list = (DList *)malloc(sizeof(DList));
    Position head = dlist_make_node(0); 
    if(NULL == head ) return NULL;
    if(NULL != double_list){
        double_list->head = head;
        double_list->tail = head;
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
    pnode->next = head->next;
    pnode->pre = head;

    if(NULL != head->next){
        head->next->pre = pnode;
    }

    head->next = pnode;
    return pnode;
}

Position dlist_insert_last(DList *dlist, Position pnode){
    Position last = NULL;
    last = dlist_get_tail(dlist);

    pnode->pre = last;
    pnode->next = NULL;

    dlist->tail = pnode;
    ++(dlist->size);

    last->next = pnode;  
    return pnode; 
}

Position dlist_insert(DList *dlist, Position pnode, PNode s){
    //: TODO    
}

void dlist_create_from_head(DList *dlist, Item array[], int num){
    int item_count;
    for(item_count = 0; item_count < num; ++item_count){
        dlist_insert_first(dlist, dlist_make_node(array[item_count]));
    }
}


void dlist_create_from_tail(DList *dlist, Item array[], int num){
    int item_count;
    for(item_count = 0; item_count < num; ++item_count){
        dlist_insert_last(dlist, dlist_make_node(array[item_count]));
    }
}

Position dlist_get_previous(DList *dlist, PNode pnode){
    return pnode->pre;
}

Position dlist_get_next(DList *dlist, PNode pnode){
    return pnode->next;
}

Position dlist_find(DList *dlist, Item item){
    Position head = dlist_get_head(dlist);
    Position tmp = head->next;
    
    if(NULL != tmp){
        while(tmp != NULL && tmp->item != item){
           tmp = tmp->next; 
        }
        return tmp;
    } else {
        return NULL;
    }
}

void dlist_delete(DList *dlist, Item item){
    if(!dlist_is_empty(dlist)){
        Position tmp;
        tmp = dlist_find(dlist, item);
        if(NULL != tmp){
            if(dlist_is_tail(dlist, tmp)){
                // Adjust tail pointer
                dlist->tail = tmp->pre;
                tmp->pre->next = NULL;

                // Set tmp NULL
                tmp->pre = NULL;
                tmp->next = NULL;
                --(dlist->size);
                dlist_free_node(tmp);
            }else{
                tmp->pre->next = tmp->next;
                tmp->next->pre = tmp->pre;
                tmp->next = NULL; 
                tmp->pre = NULL; 
                --(dlist->size);
                dlist_free_node(tmp);
            }
        }
    }
}

void dlist_clear(DList *dlist){
    if(NULL == dlist)return;
    Position head = NULL, tmp = NULL;
    head = dlist_get_head(dlist);
    if(!dlist_is_empty(dlist)){
        while(head->next != NULL){
            tmp = head->next;
            if(dlist_is_tail(dlist, tmp)){
                dlist->tail = tmp->pre;
                --(dlist->size);
                head->next = NULL;
                tmp->pre = NULL;
                tmp->next = NULL;
                dlist_free_node(tmp);
            }else{
                tmp = head->next;
                head->next = tmp->next;
                tmp->next->pre = head;
                tmp->next = NULL;
                tmp->pre = NULL;
                --(dlist->size);
                dlist_free_node(tmp);
            }
        }
    }
}

void dlist_destroy(DList *dlist){
    dlist_clear(dlist);
    dlist_free_node(dlist_get_head(dlist));
    free(dlist); 
}

void dlist_print(DList *dlist){
    if(!dlist_is_empty(dlist)){
        Position head = dlist_get_head(dlist);
        if(NULL != head){
            Position node = head->next;
            while(node != NULL){
                printf("dlist item:\t%d\n", node->item);
                node = node->next;
            }
        }
    }else{
        printf("The dlist is empty\n");
    }
}
