#ifndef _STACK_H
#define _STACK_H

#define a type class
typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

/* Create a NULL stack*/
Stack stack_create();

/* if stack is NULL, return true */
bool stack_is_empty(Stack S);

/* Push a element to a stack of S */
void stack_push(Stack S, ElementType value);

/* Pop a element to a stack of S */
void stack_pop(Stack S);

/* return the  element to a stack of top */
ElementType stack_top(Stack S);

struct Node{
    ElementType element;
    PtrNode     next;
};
#endif
