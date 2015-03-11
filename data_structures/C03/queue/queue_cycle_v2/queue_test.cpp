/*************************************************************************
	> File Name: queue_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月10日 星期二 23时35分18秒
 ************************************************************************/


#include <stdio.h>
#include "queue.h"

int main()
{
    Item array[] = {1,2,3,4,5,6,7,8,9,0};
    const uint32_t size = sizeof(array)/sizeof(Item);
    Queue *queue = queue_init();
    queue_create(queue, array, size);
    queue_print(queue);
    queue_destroy(queue);
    return 0;
}
