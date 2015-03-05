/*************************************************************************
	> File Name: double_list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月05日 星期四 22时27分57秒
 ************************************************************************/

#include "double_list.h"

bool dlist_is_empty(Dlist dlist){
    return dlist->next == NULL;
}

bool dlist_is_last(Dlist dlist, Positon plist){
    return plist->next == NULL;
}

Dlist dlist_init(){
    Dlist *plist = (Dlist)malloc(sizeof(struct Node)); 
    if(plist != NULL){
        plist->item = 0;
        plist->pre = NULL;
        plist->next = NULL:
    }else{
        return NULL;
    }
    return plist;
}

void dlist_insert_before(Dlist plist, Position p, Item item){
    Dlist tmp = (Dlist)malloc(sizeof(struct Node));
    if(!tmp){
        tmp->item = item;
        tmp->next = p;
        tmp->pre = p->pre; 
        p->pre->next = tmp;
        p->pre = tmp;
    }
}

void dlist_create(Dlist dlist, Item array[], int item_num){
    int item_count;
    Dlist head = dlist_init();
    for(item_count = 0; item_count < n; ++item_count){
        Dlist dnode = (Dlist)malloc(sizeof(struct Node));
        if (!dnode){
            dnode->item = array[item_count];
            dnode->pre = head;
            dnode->next = head->next;
            head->next = dnode;
        }
    }
}


