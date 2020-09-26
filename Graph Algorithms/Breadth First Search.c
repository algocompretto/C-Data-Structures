#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct edge_node
{
    int v;
    int weight;
    struct edge_node * next;
};

typedef struct edge_node edge_node;

struct graph
{
    edge_node * * edges; //Declaramos o array assim pq não sabemos a quantidade de dado que vai ser inserido
    int nb_nodes;
    int nb_edges;
    bool is_directed;
};

typedef struct graph graph;

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

void graph_dfs(graph * g, int u, bool visited[])
{
    if(visited[u])
        return ;
    printf("%d\t",u);
    visited[u] = true;
    edge_node * e = get_neighbors(g, u);
    while(e != NULL)
    {

        graph_dfs(g, e->v, visited);
        e = e->next;
    }
}

void graph_bfs(graph * g , int u)
{
    bool visited[g->nb_nodes];
    int i;
    for(i=0;i<g->nb_nodes;i++)
        visited[i] = false;
    visited[u] = true;

    queue * q = create_queue();
    push_queue(q,u);
    while(!empty_queue(q))
    {
        int u = pop_queue(q);

        visited[u] = true;
        printf("%d\t",u);
        edge_node * e = get_neighbors(g, u);
        while(e != NULL)
        {
            if (!visited[e->v])
            {
                push_queue(q,e->v);
                visited(e->v) = true;
            }
            e = e->next;
        }

    }

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
