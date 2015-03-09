/*************************************************************************
	> File Name: queue_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月10日 星期二 00时23分41秒
 ************************************************************************/


#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{
    Queue *queue = NULL;
    queue = queue_init();
    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 2);
    queue_push(queue, 2);
    queue_push(queue, 2);

    return 0;
}
