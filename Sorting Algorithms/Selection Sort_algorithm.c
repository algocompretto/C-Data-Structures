#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int arr[],int n)
{
    int target;
    for(target=0;target<n-1;target++)
    {
        int min_index = target;
        int i;
        for(i = target+1;i<n;i++)
        {
            if(arr[min_index] > arr[i])
                min_index = i;
        }
        int tmp = arr[target];
        arr[target] = arr[min_index];
        arr[min_index] = tmp;
    }
}

int main()
{
    int arr[5] = {542,62,1,32,29};
    selection_sort(arr,5);
    int i;

    for (i=0;i<5;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}
