#include<stdio.h>

int main(){
    int arr[] = {1,23,6,7,4,2};
    int n = 6;
    int x;
    printf("Enter Your number ");
    scanf("%d", &x);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x){
            printf("Found");
            return 0;
        }
    }
    printf("Not found");
    return 0;
}