#include <stdio.h>
#include <stdlib.h>

void f (int n)
{
    if (n == 0)
        printf("0");
    else
    {
        printf("(");
        f(n-1);
        printf(" + ");
        f(n-1);
        printf(")");
    }
}

int main()
{
    int n = 3;

    printf("0 = ");

    f(n);
    return 0;
}
