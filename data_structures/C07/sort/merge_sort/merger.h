/*************************************************************************
	> File Name: merger.h
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 10:53:58 AM CST
 ************************************************************************/

#ifndef _MERGER_H
#define _MERGER_H

typedef int ItemType;

/* Merge two array to a tmp array */
void merge(ItemType array[], ItemType tmp_array[], int left_pos, int right_pos, int right);

/* merge sort*/
void merge_sort(ItemType array[], ItemType tmp_array[], int left_pos, int right_pos);

/* sort */
void sort(ItemType array[], int item_size);
#endif
