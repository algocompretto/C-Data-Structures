#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    int ans=1, i;
    for(i=2;i<=n;i++)
    {
        ans *= i;
    }
    return ans;
}

double expo(double x)
{
    int i;
    double ans=0;
    for(i=0;pow(x,i)/factorial(i)>0.001;i++)
    {
        ans = pow(x,i)/factorial(i);
    }
    return ans;
}
int main()
{
    printf("%f", exp(10));
    return 0;
}
