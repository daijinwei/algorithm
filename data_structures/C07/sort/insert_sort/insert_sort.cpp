/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月17日 星期二 22时00分44秒
 ************************************************************************/

#include <stdio.h>
typedef int ItemType;

void insert_sort(ItemType array[], int num){
    ItemType tmp;

    int count;  // sort counts
    int index;  // array index
    for(count = 1; count < num; ++count){     // max count, num - 1
        tmp = array[count];
        // compare array[index] and tmp
        for(index = count;index > 0 && array[index -1] > tmp; --index){
            array[index] =  array[index - 1];
        }
        array[index] = tmp;
    }
}


int main(){
    ItemType array[] = {5,4,2,3,78,22,33,44,55,66,7,7};
    const int array_size = sizeof(array) / sizeof(int);
    insert_sort(array, array_size);

    int i;
    for(i = 0; i < array_size; ++i){
        fprintf(stdout, "Item\t%d\n", array[i]);
    }
}
