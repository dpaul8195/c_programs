#include<stdio.h>

void merge(int arr1[], int m, int arr2[], int n, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while(i<m && j < n)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while(i<m)
    {
        arr3[k++] = arr1[i++];
    }
    while(j<n)
    {
        arr3[k++] = arr2[j++];
    }
}

void print(int arr[],int n)
{
    for(int i = 0; i< n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void main()
{
    int arr1[] = {2,4,6,8};
    int m = 4;
    int arr2[] = {1,3,5,7,9,10,11,15};
    int n = 8;
    int p = m+n;
    int arr3[p];
    merge(arr1,m, arr2, n, arr3);
    print(arr3,p);
}