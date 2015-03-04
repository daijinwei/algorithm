#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*Return true if L is empty*/
bool list_is_empty(List L){
    return L->next == NULL;
}

/*  return true if p is the last position in list L */
bool list_is_last(List L, Position p){
    return p->next == NULL;
}

void list_create_from_head(List L, ElementType array[], int n){
    int i = 0;
    Position tmp_node;
    L = (Position)malloc(sizeof(struct Node));
	L->next = NULL;
	for(i; i < n; ++i){
        tmp_node = (Position)malloc(sizeof(struct Node));
        tmp_node->element = array[i];
        tmp_node->next = L->next;
        L->next = tmp_node;
    }
}

void list_create_from_tail(List L, ElementType array[], int n){
    int i = 0;
    Position tail_previous, tmp_node;
    L = (Position)malloc(sizeof(struct Node));
    L->next = NULL;
    tail_previous = L;
	for(i; i < n; ++i){
        tmp_node = (Position)malloc(sizeof(struct Node));
        tmp_node->element = array[i];
        tail_previous->next = tmp_node;
        tail_previous = tmp_node;
    }
}

Position list_find_element(List L, ElementType value){
    Position tmp;
    tmp = L->next;
    while(tmp != NULL && (tmp->element == value)) {
        tmp = tmp->next;	
    }
}

Position list_find_previous(List L, ElementType value){
    Position tmp;
    tmp = L;
    while(tmp->next != NULL && tmp->next->element != value){
        tmp = tmp->next;	
    }
    return tmp;
}	

void list_delete_element(List L, ElementType value){
    Position pre, tmp;
    pre = list_find_previous(L,value);	

    if(!list_is_last(L, pre)) {
        tmp = pre->next;			// The current value
        pre->next = tmp->next;
        free(tmp);
    }
}

void list_insert(List L, Position p, ElementType value){
    Position tmp;
    tmp = (Position)malloc(sizeof(struct Node));
    if(!tmp) {
        return;	
    }

    tmp->element = value;
    tmp->next = p->next;
    p->next = tmp;
}

void list_clear(List L){
    Position p, tmp;
    p = L->next;
    L->next=NULL;		//	

    while(p != NULL){	
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

Position list_header(List L){
    return L;
}

Position list_first(List L){
    if(L->next != NULL)
        return L->next;
}
