#include <stdlib.h>
#include "list.h"

bool stack_is_empty(Stack S){
    return S->next == NULL;
}

void stack_make_empty(Stack S){
    if(NULL == S){
        return;
    }else{
        while(!stack_is_empty(S)){
            stack_pop(S);
        }
    }
}

void stack_push(Stack S, ElementType value){
    PtrToNode cell;
    if(NULL == S){
        return;
    }else{
        cell = (Stack)malloc(sizeof(struct Node));
        cell->element = value;
        cell->next = S->next;
        S->next = cell;
    }
}

void stack_pop(Stack S){
    PtrToNode first_cell;
    if(stack_is_empty(S)){
        return;
    }else{
        first_cell = S->next;
        S->next = S->next->next;
        free(first_cell);
    }
}

ElementType stack_top(Stack S){
    if(stack_is_empty(S)){
        return 0;
    }else{
        return S->next->element;
    }
}

Stack stack_create(){
    Stack s;
    s = (Stack)malloc(sizeof(struct Node));
    if(NULL == s) {
        return NULL;
    }
    s->next = NULL;
    stack_make_empty(s);
    return s;
}
