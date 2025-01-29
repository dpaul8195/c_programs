#include<stdio.h>
#include<limits.h>

int max(int *arr, int n){
    int MAX = INT_MIN;
    for(int i = 0; i< n; i++){
        if(arr[i] > arr[MAX]){
            MAX = i;
        }
    }
    return arr[MAX];
}

void countsort(int *arr, int n){
    int x = max(arr, n);
    int A[x + 1];
    for(int i = 0; i< x + 1; i++){
        A[i] = 0;
    }

    for(int i = 0; i < n; i++){
        ++A[arr[i]];
    }

    for(int i = 1; i < x + 1; i++){
        A[i] = A[i] + A[i -1];
    }

    int B[n];
    for(int i = n - 1; i>=0; i--){
        B[--A[arr[i]]]= arr[i];
    }

    for(int i = 0; i< n; i++){
        arr[i] = B[i];
    }
}

void print(int *arr, int n){
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[] = {5,4,3,2,1, 8, 0};
    int n = sizeof(arr)/ sizeof(arr[0]);
    countsort(arr, n);
    print(arr, n);
}