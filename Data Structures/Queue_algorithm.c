#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue_node
{
    int value;
    struct queue_node * next;
};

typedef struct queue_node queue_node;

struct queue
{
  queue_node * front;
  queue_node * back;
  int size;
};

typedef struct queue queue;

queue * create_queue()
{
    queue * q = (queue * ) malloc(sizeof(queue));
    q->back = q->front=NULL;
    q->size = 0;
    return q;
}

bool empty_queue(queue *q)
{
    return q->size == 0;
}

void push_queue(queue *q, int value)
{
    queue_node * qn = (queue_node *) malloc(sizeof(queue_node));
    qn -> next = NULL;
    qn -> value = value;
    if (empty_queue(q))
        q->back = q->front=qn;
    else
        q ->back->next = qn, q->back = qn;
    q->size++;
}

int pop_queue(queue *q)
{
    if(empty_queue(q))
    {
        printf("Error, Queue is empty! \n");
        return 0;
    }
    int value = q->front->value;
    queue_node * qn = q->front;
    q->front = q->front->next;
    free(qn);
    q->size--;
    return value;
}

int main ()
{
    queue * q = create_queue();
    push_queue(q,5);
    push_queue(q,7);
    push_queue(q,9);

    while(!empty_queue(q))
        printf("%d\t",pop_queue(q));
    return 0;
}
