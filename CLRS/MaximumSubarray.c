#include<stdio.h>
#include<limits.h>

int maxsub(int* arr, int n, int* start, int* end){
    int i = 0;
    int max = INT_MIN, sum = 0;
    int temp_start = 0;
    while(i <  n)
    {
        sum = sum + arr[i];
        if(sum > max){
            max = sum;
            *start = temp_start;
            *end = i;
        }
        if(sum < 0)
        {
            sum = 0;
            temp_start = i + 1;
        }
        i++;
    }
    return max;
}

void main(){
    int arr[] = {2,-4,6,1, -17, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = 0;
    printf("Sum is %d\n", maxsub(arr , n, &start, &end));
    printf("index is (%d, %d)", start, end);
}