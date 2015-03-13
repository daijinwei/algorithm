#ifndef _STACK_H
#define _STACK_H

#define a type class
typedef int ElementType;

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;

/* Init a empty stack*/
Stack stack_init();

/* if stack is NULL, return true */
bool stack_is_empty(Stack S);

/* Push a element to a stack of S */
void stack_push(Stack S, ElementType value);

/* Pop a element to a stack of S */
void stack_pop(Stack S);

/* return the  element to a stack of top */
ElementType stack_top(Stack S);

/* Init a empty stack*/
void stack_destroy(Stack s);

struct Node{
    ElementType element;
    PtrNode     next;
};

#endif
