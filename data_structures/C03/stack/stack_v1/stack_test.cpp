/*************************************************************************
	> File Name: stack_test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Mar 2015 11:17:36 AM CST
 ************************************************************************/

#include<stdio.h>
#include "stack.h"
int main(){
    Stack s = NULL;
    s = stack_init();
    stack_destroy(s);
}
