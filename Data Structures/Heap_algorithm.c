#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heap
{
    int * arr;
    int size;
};
typedef struct heap heap;

heap * create_heap(int max_size)
{
    heap * h = (heap *) malloc(sizeof(heap));
    h->arr = (int *) malloc(sizeof(int) * max_size);
    h->size = 0;
    int i;
    for(i = 0;i<max_size;i++)
        h->arr[i] = 0;
    return h;
}

bool empty_heap(heap * h)
{
    return h->size == 0;
}

void swap(int * nb1,int * nb2)
{
    int tmp = * nb1;
    *nb1 = *nb2;
    *nb2 = tmp;
}

int max(int nb1,int nb2)
{
    return nb1 > nb2 ? nb1 : nb2;
}

int min(int nb1,int nb2)
{
    return nb1 < nb2 ? nb1 : nb2;
}

void insert_max_heap(heap *h, int value)
{
    h->arr[++h->size] = value;
    int child_index = h->size;
    while(child_index > 1 && h->arr[child_index] > h->arr[child_index / 2])
    {
        swap(&h->arr[child_index], &h->arr[child_index/2]);
        child_index /= 2; //This instruction was not included in the video , it is essential to update the child to its previous parent
    }
}

int main()
{

    return 0;
}
