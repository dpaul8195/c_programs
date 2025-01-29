#include<stdio.h>

int max_num(int* arr, int n){
    int greatest = 0;
    for(int i = 0; i< n; i++){
        if(arr[i] > arr[greatest]){
        greatest = i;
        }
    }
    return arr[greatest];
}

int missing(int *arr, int n){
    int max = max_num(arr, n);
    int A[max + 1];
    for(int i = 0; i<= max; i++){
        A[i] = 0;
    }
    for(int i = 0; i< n; i++){
        A[arr[i]]++;
    }
    for(int i = 0; i< n; i++){
        if(A[i] == 0){
            return i;
        }
    }
}

void main(){
    int arr[] = {1,2,0,4,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = missing(arr, n);
    printf("%d", x);
}