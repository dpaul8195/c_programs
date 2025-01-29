#include<stdio.h>

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void movezeroes(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        int j = i+1;
        while(arr[i] == 0 && j <n)
        {
            if(arr[j] != 0)
            {
                swap(&arr[i],&arr[j]);
                break;
            }
            j++;
        }
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
    int arr[] = {1,0,5,0,9,0,0,8,90};
    movezeroes(arr, 9);
    print(arr,9);
}