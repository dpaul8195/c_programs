#include<stdio.h>

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
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}