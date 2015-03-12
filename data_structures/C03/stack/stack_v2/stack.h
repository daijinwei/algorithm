/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Mar 2015 05:33:06 PM CST
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#define STACK_MAX_SIZE  128 
typedef int Item; 

typedef struct{
    int top;
    Item data[STACK_MAX_SIZE];
}Stack;

/* Return true if stack is emtpy */
bool stack_is_empty(Stack *s);

/* Return true if stack is full */
bool stack_is_full(Stack *s);

/* Init a stack */
Stack *stack_init();

/* Push a Item to stack*/
void stack_push(Stack *s, Item item);

/* Pop a Item to stack */
void stack_pop(Stack *s);

/* Return a Item to stack */
Item stack_top(Stack *s);

/* Destory the stack */
void stack_destroy(Stack *s);
#endif
