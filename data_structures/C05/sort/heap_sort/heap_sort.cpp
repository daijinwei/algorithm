/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Mar 2015 04:06:02 PM CST
 ************************************************************************/

#include "heap_sort.h"

void heap_insert_to_index(ItemType array[], int index){
    int parent;
    ItemType tmp;
    // Find parent node
    parent = (index -1)/2;

    // The node is inserted.
    tmp = array[index];

    // Adjust the index and parent postion
    while(0 <= parent && index > 0){
        if(array[parent] <= tmp){       
            break;
        }

        array[index] = array[parent];
        index = parent;
        parent = (index -1)/2;
    }
    array[index] = tmp;
}

void heap_insert(ItemType array[], int index, ItemType item){
    array[index] = item;
    heap_insert_to_index(array, index);
}

ItemType head_delete(ItemType array[], int index, int max){
    ItemType delete_item  = array[index];
    int left;
    left = 2*index + 1;

    /**/
    while(left < max){
        // Find the min item
        if((left + 1)< max && array[left + 1] < array[left]){
            left++;
        }

        if(delete_item <= array[left]){
            break;
        }

        array[index] = array[left];
        index = left;
        left = 2*index = 1;
    }

    a[index] = delete_item;
}
