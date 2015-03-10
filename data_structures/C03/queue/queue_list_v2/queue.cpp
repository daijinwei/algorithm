/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年03月09日 星期一 23时28分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Position queue_make_node(Item item){
    QNode node = (QNode)malloc(sizeof(struct Node));
    if(!node){
        return NULL;
    }else{
        node->item = item;
        node->pre = NULL;
        node->next = NULL;
    }
    return node;
}

void queue_free_node(QNode qnode){
    free(qnode);
    qnode = NULL;
}

Position queue_get_head(Queue *queue){
    return queue->head;
}

Position queue_get_tail(Queue *queue){
    return queue->tail;
}

int queue_get_size(Queue *queue){
    return queue->size;
}

bool queue_is_empty(Queue *queue){
    return (0 == queue_get_size(queue)) && 
        (queue_get_head(queue) == queue_get_tail(queue));
}

bool queue_is_full(Queue *queue){
	return queue->size >= queue->max_size;
}

Queue *queue_init(){
    QNode head = NULL;
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if(!queue){
        return NULL;
    }else{
        if(!(head = queue_make_node(0))){
            return NULL; 
        }else{
            queue->head = head;
            queue->tail = head;
            queue->max_size = QUEUE_MAX_SIZE;
            queue->size = 0;
        }
    }
    return queue;
}

void queue_push(Queue *queue, Item item){
	if(!queue_is_full(queue)){
    	QNode node = queue_make_node(item);
    	if(NULL != node){
			if(queue_is_empty(queue)){
				queue->head->next = node;	
			}

			Position tail = queue_get_tail(queue);	
			tail->next = node;

			node->pre = tail;
			node->next = NULL;

			queue->tail = node;
			++(queue->size);
    	}
	}
}

void queue_pop(Queue *queue){
    if(queue_is_empty(queue)) return;

	// Get the first node
	QNode head = queue_get_head(queue);
    QNode node = head->next;
	if(NULL == head->next->next){	// Queue has only one node
		head->next = NULL;
		queue->tail = head;
	}else{
		head->next->next->pre = head;
		head->next = node->next;	
	}

	node->pre = NULL;
	node->next = NULL;

	--(queue->size);

	queue_free_node(node);
}

Position queue_front(Queue *queue){
	return queue_get_head(queue)->next;
}

Position queue_back(Queue *queue){
	return queue_get_tail(queue);
}

void queue_create(Queue *queue, Item array[], int num){
	int item_num;
	for(item_num = 0; item_num < num; ++item_num){
		queue_push(queue, array[item_num]);
	}	
}

void queue_print(Queue *queue){
	Position tmp = NULL;
	while(!queue_is_empty(queue)){
		tmp = queue_front(queue);
		fprintf(stdout, "Item\t%d\n", tmp->item);
		queue_pop(queue);
	}
}

void queue_clear(Queue *queue){
	while(!queue_is_empty(queue)){
		queue_pop(queue);
	}
}

void queue_destroy(Queue *queue){
	queue_clear(queue);	
	free(queue);
}
