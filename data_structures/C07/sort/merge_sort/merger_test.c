/*************************************************************************
	> File Name: merger_test.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 11:02:12 AM CST
 ************************************************************************/

#include<stdio.h>
#include "merger.h"

int main(){
    ItemType array[] = {1,2,5,76,87,8,2,4,476,7,3,56,345,6,3456,3245,623};
    const int item_size = sizeof(array) / sizeof(ItemType);
    sort(array, item_size);
    for(int i = 0; i < item_size; i++){
        fprintf(stdout, "Item\t%d\n",array[i]);
    }

    return 0;
}
