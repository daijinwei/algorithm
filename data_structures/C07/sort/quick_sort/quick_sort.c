/*************************************************************************
	> File Name: quick_sort.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 04:30:51 PM CST
 ************************************************************************/

#include<stdio.h>

typedef int ItemType;

int partition(ItemType array[], int left, int right){
    // Select a base Item, is used to be compared
    int base = left;
    int left_pos = left;
    int right_pos = right;
    ItemType tmp = array[left];
    while(left_pos < right_pos){
        while(left_pos < right_pos && array[right_pos] >= tmp){
            right_pos--;
        }
        // array[right_pos] < tmp
        if(left_pos < right_pos){
            array[left_pos] = array[right_pos]; 
        }

        // array[right_pos] > tmp
        while(left_pos < right_pos && array[left_pos] >= tmp){
            left_pos++;
        }
        if(left_pos < right_pos){
           array[right_pos] = array[left_pos]; 
        }
    }
    array[left_pos] = tmp;
    return left_pos;
}

void quick_sort(ItemType array[], int left, int right){
    if(left >= right) return;
    int position = partition(array, left, right);
    quick_sort(array, left, position - 1);
    quick_sort(array, position + 1, right);
}
