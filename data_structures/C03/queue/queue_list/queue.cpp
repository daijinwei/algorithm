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
            queue->size = 0;
        }
    }
    return queue;
}

void queue_push(Queue *queue, Item item){
    QNode node = queue_make_node(item);
    if(!node){
        return;
    }else{
    	Position head = NULL;
    	head = queue->head;
        if(queue_is_empty(queue)){
            queue->tail = node;
        }

        node->pre = head;
        node->next = head->next;

        if(NULL != head->next){
            head->next->pre = node;
        }
        head->next = node;
        ++(queue->size);
    }
}

void queue_pop(Queue *queue){
    if(queue_is_empty(queue)) return;
    
    QNode tail = queue_get_tail(queue);
    queue->tail = tail->pre; 

    tail->pre->next = NULL;
    --(queue->size);

    tail->pre = NULL;
    tail->next = NULL;
    queue_free_node(tail);
}

void queue_print(Queue *queue){
	Position tmp = NULL;
	while(!queue_is_empty(queue)){
		tmp = queue_get_tail(queue);	
		fprintf(stdout, "Item\t%d\n", tmp->item);
		queue_pop(queue);
	}
}
