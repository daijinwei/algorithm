/*************************************************************************
	> File Name: stack_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Mar 2015 06:51:15 PM CST
 ************************************************************************/
#include <stdio.h>
#include "stack.h"

int main(){
    Stack *s = NULL;
    Item e = 0;
    s = stack_init();
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_push(s, 4);
    stack_push(s, 5);
    stack_push(s, 6);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    e = stack_top(s);
    fprintf(stdout, "Item \t%d\n", e);
    stack_pop(s);
    stack_destroy(s);
}
