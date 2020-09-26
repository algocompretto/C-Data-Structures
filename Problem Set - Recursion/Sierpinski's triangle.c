#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64

void init_matrix(char matrix [MAX_SIZE][MAX_SIZE])
{
    int i, j;
    for(i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
            matrix[i][j] = 0;
    }
}

void print_matrix(char matrix [MAX_SIZE][MAX_SIZE], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%c",matrix[i][j]);
        printf("\n");
    }
}

void f(char matrix[MAX_SIZE][MAX_SIZE], int begi, int endi, int begj, int endj)
{
    if (begi == endi ||  begj == endj)
        matrix[begi][begj] = '#';
    else
    {
        f(matrix, begi, (begi+endi)/2, begj, (begj+endj)/2);
        f(matrix, (begi+endi)/2, endi, begj, (begj+endj)/2);
        f(matrix, (begi+endi)/2, (begj+endj)/2, endj);
    }
}

int main()
{
    char matrix[MAX_SIZE][MAX_SIZE];
    init_matrix(matrix);

    int n=8;
    f(matrix,0,n,0,n);
    print_matrix(matrix, n);

    return 0;
}
