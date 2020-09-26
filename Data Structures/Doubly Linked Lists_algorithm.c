#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
    int value;
    struct list_node * next;
    struct list_node * previous;
};

typedef struct list_node list_node;

struct list
{
    list_node * head;
    list_node * tail;
    int size;
};

typedef struct list list;

list * create_list()
{
    list * l = (list *) malloc(sizeof(list));
    l -> head = NULL;
    l -> tail = NULL;
    l -> size = 0;
    return l;
}

bool empty_list(list * l)
{
    return l -> size == 0;
}

void push_front_list(list *l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln -> value = value;
    ln -> next = ln -> previous = NULL;
    if(empty_list(l))
    {
        l->head = l->tail =ln;
        l->size++;
        return ;
    }

    ln->next=l->head;
    l->head->previous = ln;
    l->head = ln;
    l->size++;
}

void push_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln -> value = value;
    ln->next = ln->previous = NULL;

    if(empty_list(l))
    {
        l->head = l->tail = ln;
        l->size++;
        return ;
    }
    ln->next = l->head;
    l->head = ln;

    l->size++;
}

int pop_front_list(list * l)
{
    if(empty_list(l))
    {
        printf("Error, empty list!");
        return 0;
    }
    int value = l -> head -> value;
    list_node * ln = l -> head;
    if(l->size==1)
    {
        l->size--;
        free(l->head);
        l->head=l->tail=NULL;
        return value;
    }

    l -> head = l->head->next;
    free(ln);
    l->size--;
    return value;
}

int pop_back_list(list * l)
{
    if(empty_list(l))
    {
        printf("Error, empty list!");
        return 0;
    }
    int value = l->tail->value;
    if(l->size == 1)
    {
        free(l->tail);
        l->head = l->tail = NULL;
        l->size --;
        return value;
    }
    list_node * ln = l-> tail;
    l->tail = l->tail->previous;
    l->tail->next = NULL;
    free(ln);
    l->size--;
    return value;
}

int main(void)
{
    list * l = create_list();
    push_front_list(l,5);
    push_front_list(l,3);
    push_front_list(l,7);
    while(!empty_list(l))
        printf("%d\t", pop_front_list(l));
    return 0;
}
