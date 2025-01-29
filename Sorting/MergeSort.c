#include<stdio.h>

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    int index = s;
    for(int i=0; i< len1; i++)
    {
        first[i] = arr[index++];
    }
    index = mid +1;
    for(int i=0; i< len2; i++)
    {
        second[i] = arr[index++];
    }
    int i = 0,j = 0, k= s;
    while(i < len1 && j < len2)
    {
        if(first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }
    while(i< len1)
    {
        arr[k++] = first[i++];
    }
    while(j< len2)
    {
        arr[k++] = second[j++];
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = (s + e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s ,e);
}

void main()
{
    int arr[9] = {1,2,4,45,53,22,2,20,0};
    mergeSort(arr,0,8);
    print(arr,9);
}