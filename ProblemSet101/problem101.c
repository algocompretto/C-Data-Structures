#include <stdio.h>
#include <stdlib.h>

main ()
{
    float a,b;
    float temp; //variável para troca

    printf("Enter the first number:");
    scanf("%f", &a);

    printf("Enter the second number:");
    scanf("%f", &b);

    tmp=a;
    a=b;
    b=tmp;

    printf("A = %.2f \t b= %.2f",a,b);
    return 0;
}
