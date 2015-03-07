/*************************************************************************
	> File Name: double_list_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月07日 星期六 17时31分20秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include "double_list.h"

using namespace std;

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,0,100,911,110};
    const uint32_t array_size = sizeof(array) / sizeof(int);

    DList *dlist = dlist_init();

    // dlist_create_from_head(dlist, array, array_size);
    dlist_create_from_tail(dlist, array, array_size);
    int size = dlist_get_size(dlist);
    printf("\ndlist size:\t%d\n", size);
    dlist_print(dlist);

    dlist_delete(dlist, 100);
    size = dlist_get_size(dlist);
    printf("\ndlist size:\t%d\n", size);
    dlist_print(dlist);

    // Clear the dlist 
    dlist_clear(dlist);
    size = dlist_get_size(dlist);
    printf("\ndlist size:\t%d\n", size);

    //
    dlist_print(dlist);
    dlist_destroy(dlist);
    return 0;
}
