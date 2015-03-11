/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2015年03月10日 星期二 22时49分52秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdint.h>

#define QUEUE_MAX_SIZE 1024 
typedef uint32_t Item;

/**
 * Define the cycle queue
 * 
 * */
typedef struct{
    uint32_t queue_size; 
    uint32_t head;
    uint32_t tail;
    Item *base;
}Queue;

/* Init a queue */
Queue *queue_init();

/* Retrun false if a queue is empty */
bool queue_is_empty(Queue *queue);

/* Retrun false if a queue is full */
bool queue_is_full(Queue *queue);

/* Push a Item to queue */
void queue_push(Queue *queue, Item item);

/* Pop a item from queue */
Item queue_pop(Queue *queue);

/* Return a item from queue front */
Item queue_front(Queue *queue);

/* Return a item from queue back */
Item queue_back(Queue *queue);

/* Create a queue */
void queue_create(Queue *queue, Item array[], int num);

/* print queue */
void queue_print(Queue *queue);

/* Clear queue */
void queue_clear(Queue *queue);

/* Clear queue */
void queue_destroy(Queue *queue);

#endif
