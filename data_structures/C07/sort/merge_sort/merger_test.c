/*************************************************************************
	> File Name: merger_test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 11:02:12 AM CST
 ************************************************************************/

#include<stdio.h>
#include "merger.h"

int main(){
    ItemType array[] = {345,6,3456,3245,623,2,3,4,9,5,10000,22,423,553};
    const int item_size = sizeof(array) / sizeof(ItemType);
    sort(array, item_size);
    for(int i = 0; i < item_size; i++){
        fprintf(stdout, "Item\t%d\n",array[i]);
    }

    return 0;
}
