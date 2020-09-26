#include <stdio.h>
#include <stdlib.h>


double pow(double b, int e)
{
    int result = 1;
    int i;
    for (i=0;i<b;i++)
    {
        result *= b;
    }
    return result;

}

main ()
{
    float base, ans;
    int expo;

    printf("Enter the base of the expoent:");
    scanf("%f", &base);

    printf("Enter the expoent:");
    scanf("%d", &expo);

    ans = power(base,expo);

    printf("Answer is %.2f",ans);

    return 0;
}
