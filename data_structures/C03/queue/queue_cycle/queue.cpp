/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2013年03月10日 星期二 22时57分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* queue_init(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if(queue){
        queue->base = (Item *)malloc(QUEUE_MAX_SIZE*sizeof(Item)); 
        queue->head = 0;
        queue->tail = 0;
        queue->queue_size = 0;
    }
    return queue;
}

bool queue_is_empty(Queue *queue){
    return 0 == queue->queue_size;   
}

bool queue_is_full(Queue *queue){
    return QUEUE_MAX_SIZE == queue->queue_size;    
}

void queue_push(Queue *queue, Item item){
    if(queue_is_full(queue)) return;

    queue->base[queue->tail] = item;
    ++(queue->queue_size);
    // Control cycyle queue array index
    queue->tail = (queue->tail + 1) % QUEUE_MAX_SIZE;
}

Item queue_pop(Queue *queue){
    if(!queue_is_empty(queue)){
        Item tmp = queue->base[queue->head]; 
        --(queue->queue_size);
        queue->head = (queue->head + 1) % QUEUE_MAX_SIZE;
        return tmp;
    }
}

Item queue_front(Queue *queue){
    if(!queue_is_empty(queue)){
        return queue->base[queue->head];
    }
}

Item queue_back(Queue *queue){
    if(!queue_is_empty(queue)){
        return queue->base[queue->tail - 1];
    }
}

void queue_create(Queue *queue, Item array[], int num){
    int item_num = 0;
    for(item_num; item_num < num; ++item_num){
        queue_push(queue, array[item_num]);
    }
}

void queue_print(Queue *queue){
    int num = 0;
    while(!queue_is_empty(queue)){
        num = queue_pop(queue);
        fprintf(stdout, "Item\t%d\n", num);
    }
}

void queue_clear(Queue *queue){
    int num;
    while(!queue_is_empty(queue)){
        num = queue_pop(queue);
    }
}

void queue_destroy(Queue *queue){
    queue_clear(queue);
    free(queue);
}
