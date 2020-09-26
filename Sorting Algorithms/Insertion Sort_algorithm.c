#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        int tmp = arr[i];
        j = i;
        while (j > 0 && arr[j-1] > tmp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = tmp;
    }
}

void print_arr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int arr[5] = {545,23,54,-113,32};
    print_arr(arr,5);
    printf("\n");
    insertion_sort(arr,5);
    printf("\n");
    print_arr(arr,5);
    return 0;
}
