/*************************************************************************
	> File Name: quick_sort_test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 05:09:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include "quick_sort.h"

int main(){
    ItemType array[] = {10,5,19,22,45,32,192,5455,234,45,66,4,2,1};
    const int item_size = sizeof(array)/sizeof(ItemType);
    quick_sort(array, 0, item_size - 1);
    for(int i = 0; i < item_size; i++){
        fprintf(stdout,"Item\t%d\n", array[i]);
    }
    return 0;
}
