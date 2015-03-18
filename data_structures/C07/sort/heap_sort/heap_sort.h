/*************************************************************************
	> File Name: heap_sort.h
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Mar 2015 04:03:50 PM CST
 ************************************************************************/

#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

typedef int ItemType;

/* Insert a item to min_heap index positon */
void heap_insert_to_index(ItemType array[], Item item);

/* Insert a new node to the heap */
void heap_insert(ItemType array[], int index, ItemType item);

/* Delete a item to min_heap */
void heap_delte(ItemType array[]);
#endif
