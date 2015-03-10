/*************************************************************************
	> File Name: queue_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月10日 星期二 00时23分41秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{
	Item array[] = {1,2,3,4,5,6,7,8,9};
	const int num_size = sizeof(array) / sizeof(Item);
    Queue *queue = NULL;
    queue = queue_init();
	queue_create(queue, array, num_size);

	const int queue_size = queue_get_size(queue);
	fprintf(stdout, "queue size\t%d\n", queue_size);
	queue_print(queue);

	queue_destroy(queue);
    return 0;
}
