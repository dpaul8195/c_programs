#include<stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int arr[], int n){
    for(int i = 0; i< n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

void inter(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<e){
        swap(&arr[s], &arr[e]);
        s = s+ 2;
        e = e -2;
    }
}

void main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int n = 10;
    sort(arr,n);
    inter(arr,n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}