#include <stdio.h>
#include <stdlib.h>

void f(int n, int start, int dest, int tmp)
{
    if(n >= 0)
    {
        f(n-1,start,tmp,dest);
        printf("%d --> %d \n", start, dest);
        f(n-1,tmp,dest,start);
    }
}

int main()
{
    int n=3;
    f(n,1,3,2);
    return 0;
}
