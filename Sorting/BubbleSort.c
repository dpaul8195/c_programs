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
    for(int i = 1; i< n; i++)
    {
        bool swapped = false;
        for(int j = 0; j< n - i;j++)
        {
            if(arr[j+1] < arr[j])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}