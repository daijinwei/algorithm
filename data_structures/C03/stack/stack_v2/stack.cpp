#include <stdlib.h>
#include "stack.h"

bool stack_is_empty(Stack *s){
    return 0 == s->top;
}

bool stack_is_full(Stack *s){
    return STACK_MAX_SIZE <= s->top;
}

Stack *stack_init(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s){
        s->top = 0; 
    }
    return s;
}

void stack_push(Stack *s, Item item){
    if(!stack_is_full(s)){
        ++(s->top);
        s->data[s->top] = item;
    }
}

void stack_pop(Stack *s){
    if(!stack_is_empty(s)){
        Item e = s->data[s->top];
        --(s->top);
    }
}

Item stack_top(Stack *s){
    if(!stack_is_empty(s)){
        Item e = s->data[s->top];
        return e;
    }
}

void stack_destroy(Stack *s){
    if(NULL != s){
        free(s);
        s = NULL;
    }
}
