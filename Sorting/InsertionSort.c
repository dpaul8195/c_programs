#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void main()
{
    int n;
    printf("Enter the length of the array ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    // for(int i =1; i < n;i++)
    // {
    //     int temp = arr[i];
    //     int j = i-1;
    //     for(; j>=0; j--)
    //     {
    //         if(temp < arr[j])
    //         {
    //             arr[j+1] = arr[j];
    //         }
    //         else break;
    //     }
    //     arr[j + 1] = temp;
    // }

    for(int i = 1; i< n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(arr[j] > temp && j >=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}