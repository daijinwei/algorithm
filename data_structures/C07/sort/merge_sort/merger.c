/*************************************************************************
	> File Name: merger.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Mar 2015 10:32:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "merger.h"

void merger(ItemType array[], ItemType tmp_array[], int left_pos, int right_pos, int right_end){
    int left_end;
    int item_num = right_end - left_pos +1;
    int count = 0;
    int tmp_pos = left_pos;
    left_end = right_pos - 1;

    // compare left and right Item
    while(left_pos <= left_end && right_pos <= right_end){
        if(array[left_pos] <= array[right_pos]){
            tmp_array[tmp_pos++] = array[left_pos++];
        }else{
            tmp_array[tmp_pos++] = array[right_pos++];
        }
    }
    
    // Deal with the rest Item
    while(left_pos <= left_end){
        tmp_array[tmp_pos++] = array[left_pos++];
    }
    while(right_pos <= right_end){
        tmp_array[tmp_pos++] = array[right_pos++];
    }

    /* Copy back to array */
    for(count = 0; count < item_num; count++, right_end--){
        array[right_end] = tmp_array[right_end]; 
        //array[count] = tmp_array[count]; 
    }
}

void merger_sort(ItemType array[], ItemType tmp_array[], int left_pos, int right_pos){
    int center = (left_pos + right_pos)/2;
    if(left_pos < right_pos){
        merger_sort(array,tmp_array,left_pos, center);
        merger_sort(array,tmp_array,center + 1, right_pos);
        merger(array, tmp_array, left_pos, center + 1, right_pos);
    }
} 


void sort(ItemType array[], int item_size){
    ItemType *tmp_array;
    tmp_array = (ItemType *)malloc(item_size*sizeof(ItemType));
    if(!tmp_array){
        fprintf(stdout, "Out of space\n");
    }else{
        merger_sort(tmp_array, tmp_array, 0 , item_size - 1);
        free(tmp_array);
    }
}
