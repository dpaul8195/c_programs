#include<stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int arr[], int n){
    for(int i = 0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int binarySearch(int arr[], int n, int a){
    int s = 0, e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == a){
            return mid;
        }
        else if(a > arr[mid]){
            s = mid +1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}

void main(){
    int arr[]= {1,23,5,4,3,6};
    int n = 6;
    sort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int a = 238;
    int i = binarySearch(arr, n,a);
    printf("\n%d",i);
}