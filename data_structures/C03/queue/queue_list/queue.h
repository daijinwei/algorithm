/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2015年03月09日 星期一 23时25分37秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

struct Node;
typedef struct Node *QNode;
typedef QNode Position;
typedef int Item;

/* The Node store the Queue */
struct Node{
    Item item;
    struct Node *pre;
    struct Node *next;
};

/* Define the queue */
typedef struct{
    QNode head;
    QNode tail;
    int size;
}Queue;

/* Assign the element */
Position queue_make_node(Item item);

/* Free a Node that queue node pointe */
void queue_free_node(QNode qnode);

/* Get a queue head */ 
Position queue_get_head(Queue *queue);

 /* Get a quque tail */ 
Position queue_get_tail(Queue *queue);

/* Get a queue head */ 
bool queue_is_head(Queue *queue, Position p);

/* Get a list tail */
bool Queue_is_tail(Queue *queue, Position P);

/* Get the list size */
int queue_get_size(Queue *queue);

/* Return true if queue is empty */
bool queue_is_empty(Queue *queue);

/* Init Queue */
Queue *queue_init();

/* push the QNode to the queue*/
void queue_push(Queue *queue,Item item);

/* pop the QNode to the queue*/
Queue *queue_pop();


/* pop the QNode to the queue*/
void queue_print(Queue *queue);

#endif
