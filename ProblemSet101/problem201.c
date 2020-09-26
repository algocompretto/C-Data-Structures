#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n)
{
    int ans=1;
    int i;
    for(i=2;i<=n;i++)
    {
        ans *= i;

    }
    return ans;
}

int comb (int n, int p)
{
    return factorial(n)/(factorial(p)*factorial(n-p));
}

main ()
{
    int n,p;

    printf("n: ");
    scanf("%d",&n);
    printf("p: ");
    scanf("%d",&p);

    printf("%d",comb(n,p));
    return 0;
}
