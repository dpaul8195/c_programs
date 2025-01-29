#include<stdio.h>

int search(int arr[], int n, int a){
    if(a <= arr[0]){
        return 0;
    }
    for(int i = 0; i< n; i++){
        if(arr[i] == a){
            return i;
        }
        else if(a>arr[i] && a<=arr[i+1]){
            return i+1;
        }
    }
    return -1;
}

void main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a;
    printf("Enter your number ");
    scanf("%d", &a);
    int c = search(arr, n-1, a);
    printf("%d",arr[c]);
}