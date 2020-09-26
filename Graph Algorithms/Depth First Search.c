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

graph * create_graph(int nb_nodes,bool is_directed)
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->nb_nodes = nb_nodes;
    g->nb_edges = 0;
    g->is_directed = is_directed;
    g-> edges = (graph * *) malloc(sizeof(graph *) * nb_nodes);

    int u;
    for(u=0;u<g->nb_nodes;u++)
        g->edges[u] = NULL;
    return g;
}

void print_graph(graph * g)
{
    int u;
    //para todas listas
    for(u=0; u<g->nb_nodes; u++)
    {
        printf("%d --> ",u);
        //imprime todos nós conectados em u
        edge_node * e = g->edges[u];
        while(e != NULL)
        {
            printf("%d ", e->v);
            e = e->next;
        }
        printf("\n");
    }
}

//conectar u-v com o weight weight
void graph_add_edge(graph * g,int u, int v, int weight)
{
    edge_node * e = (edge_node *) malloc(sizeof(edge_node));
    e->v = v;
    e->weight = weight;
    e->next = g->edges[u];
    g->edges[u] = e;
    if(!g->is_directed)
    {
        e = (edge_node *) malloc(sizeof(edge_node));
        e-> v = u;
        e->weight = weight;
        e->next = g -> edges[v];
        g->edges[v] = e;
    }
    g->nb_edges++;
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

int main()
{
    graph * g = create_graph(13,false);
    graph_add_edge(g,0,1,1);
    graph_add_edge(g,1,2,12);
    graph_add_edge(g,1,3,10);
    graph_add_edge(g,2,4,11);
    graph_add_edge(g,2,5,13);
    graph_add_edge(g,3,5,12);
    graph_add_edge(g,3,7,13);
    graph_add_edge(g,4,6,9);
    graph_add_edge(g,2,4,1);
    graph_add_edge(g,5,6,7);
    graph_add_edge(g,6,7,15);
    graph_add_edge(g,8,9,12);
    graph_add_edge(g,8,10,10);
    graph_add_edge(g,9,10,10);
    graph_add_edge(g,10,11,9);
    graph_add_edge(g,11,12,10);

    int i;
    bool visited[13];
    for(i=0;i<13;i++)
        visited[i] = false;
    for(i=0;i<13;i++)
        graph_dfs(g,i,visited);

    return 0;
}
