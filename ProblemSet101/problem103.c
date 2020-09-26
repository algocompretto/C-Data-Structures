#include <stdio.h>
#include <stdlib.h>

main ()
{
    int n;
    printf("N: ");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        printf("ARR[%d]: ",i);
        scanf("%i",&arr[i]);
    }
    int max = arr[0];
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }
    printf("MAX: %d",max);
    return 0;
}
