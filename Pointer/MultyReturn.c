#include<stdio.h>
#include<math.h>

void fun(int x, int *a, int *b){
    *a = x * x;
    *b = sqrt(x);
}

void main(){
    int x = 100;
    int sq, sqrt;
    fun(x, &sq, &sqrt);
    printf("%d %d",sq,sqrt);
}