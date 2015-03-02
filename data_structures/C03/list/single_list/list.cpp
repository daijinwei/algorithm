#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*Return true if L is empty*/
bool is_empty(List L){
    return L->next == NULL;
}

/*  return true if p is the last position in list L */
bool is_last(List L, Position p){
    return p->next == NULL;
}

Position find_element(List L, ElementType value){
    Position tmp;
    tmp = L->next;
    while(tmp != NULL && (tmp->element == value)) {
        tmp = tmp->next;	
    }
}

Position find_previous(List L, ElementType value){
    Position tmp;
    tmp = L;
    while(L->next != NULL && tmp->next->element != value){
        tmp = tmp->next;	
    }
    return tmp;
}	

void delete_element(List L, ElementType value){
    Position pre, tmp;
    pre = find_previous(L,value);	

    if(!is_last(L, pre)) {
        tmp = pre->next;			//	The current value
        pre->next = tmp->next;
        free(tmp);
    }
}

void insert_list(List L, Position p, ElementType value){
    Position tmp;
    tmp = (Position)malloc(sizeof(struct Node));
    if(!tmp) {
        return;	
    }

    tmp->element = value;
    tmp->next = p->next;
    p->next = tmp;
}
