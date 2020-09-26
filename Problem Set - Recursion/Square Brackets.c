#include <stdio.h>
#include <stdlib.h>

void f(int n, int b)
{
    if (b == 0)
        printf("%d",n);
    else
    {
        printf("[");

        f(n, b-1);

        printf("]");
    }
}

int main()
{
    f(56,4);
    return 0;
}
