#include<stdio.h>

int max(int *arr, int n){
    int MAX = 0;
    for(int i = 1; i< n; i++){
        if(arr[i] > arr[MAX]){
            MAX = i;
        }
    }
    return arr[MAX];
}

void countsort(int *arr, int n, int d){
    int A[10];
    for(int i = 0; i< 10; i++){
        A[i] = 0;
    }

    for(int i = 0; i< n; i++){
        ++A[(arr[i] / d) % 10];
    }

    for(int i = 1; i < 10; i++){
        A[i] = A[i] + A[i -1];
    }

    int B[n];
    for(int i = n- 1; i >=0; i--){
        B[--A[(arr[i] / d) % 10]] = arr[i];
    }

    for(int i = 0; i< n; i++){
        arr[i] = B[i];
    }
}

void radixsort(int *arr, int n){
    int x = max(arr, n);
    for(int d = 1; x/d > 0; d = d*10){
        countsort(arr, n, d);
    }
}

void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[] = {530,403,32,420,401};
    int n = sizeof(arr)/ sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
}