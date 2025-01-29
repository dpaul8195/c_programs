#include <stdio.h>

void display1(int m, int n, int arr[][n]){
    for(int i = 0; i< m; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
    }
} 

void display2(int* arr, int m, int n){
    for(int i = 0; i< m; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", *((arr + i * n) + j));
        }
    }
} 


int main()
{
	// int arr[2][3] = {1,2,3,4,57,3};
    int arr[][3] = {1,2,3,4,57,3};
    int m = 2;
    int n = 3;
    printf("Method 1\n");
    display1(m,n,arr);
    printf("\nMethod 2\n");
    display2(arr[0],m,n);
}
