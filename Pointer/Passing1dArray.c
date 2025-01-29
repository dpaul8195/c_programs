#include <stdio.h>

void display1(int arr[], int n){
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
} 

void display2(int* arr, int n){
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
} 


int main()
{
	int arr[] = {1,2,3,4,56,3};
    int n = 6;
    printf("Method 1\n");
    display1(arr,n);
    printf("\nMethod 2\n");
    display2(arr,n);
}
