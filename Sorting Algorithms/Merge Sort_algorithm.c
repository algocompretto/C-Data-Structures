#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int arr[], int beg, int end)
{
    int m = (beg+end)/2;
    int tmp_arr[end-beg+1];
    int i = beg, j = m+1;
    int k = 0;

    while(i <= m && j <= end)
    {
        if(arr[i] < arr[j])
            tmp_arr[k++] = arr[i++];
        else
            tmp_arr[k++] = arr[j++];
    }
    while(i <= m)
        tmp_arr[k++] = tmp_arr[i++];
    while(j <= end)
        tmp_arr[k++] = tmp_arr[j++];
    for (i=0;i<k;i++)
    {
        arr[beg + i] = tmp_arr[i];
    }
}

void merge_sort(int arr[],int beg, int end)
{
    if (beg == end)
        return ;
    int m = (beg+end)/2;
    merge_sort(arr,beg,m);
    merge_sort(arr,m+1,end);
    merge(arr,beg,end);
}

void print_arr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[4] = {1,2,3,4};
    merge(arr,0,3);
    print_arr(arr,4);
    return 0;
}
