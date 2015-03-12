#include <stdlib.h>
#include "stack.h"

bool stack_is_empty(Stack *s){
    return 0 == s->top;
}

bool stack_is_full(Stack *s){
    return STACK_MAX_SIZE =< s->top;
}

Stack *stack_init(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s){
        s->top = 0; 
    }
    return s;
}

void stack_push(Stack *s, Item item){
    ++(s->top);
    s->data[top] = item;
}

void stack_pop(Stack *s){
    Item e = s->data[top];
    --(s->top);
}
