#include<stdio.h>

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void main()
{
    int arr[] = {2,4,6,3,4,545,34};
    int s = 0;
    int e = 6;
    int n = 6;
    while(s<=e)
    {
        swap(&arr[s], &arr[e]);
        s++;
        e--;
    }
    for(int i = 0; i< n +1; i++)
    {
        printf("%d ",arr[i]);
    }
}