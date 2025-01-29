#include<stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1; i<=e; i++)
    {
        if(arr[i] <= pivot) count++;
    }

    int pivotIndex = s + count;

    swap(&arr[s], &arr[pivotIndex]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    return pivotIndex;
}

void print(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void quickSort(int arr[], int s, int e)
{
    if(s >= e)
    {
        return ;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

void main()
{
    int arr[] = {3,43,14,6,35,3,32};
    int n= 7;
    quickSort(arr, 0,n-1);
    print(arr,n);
}