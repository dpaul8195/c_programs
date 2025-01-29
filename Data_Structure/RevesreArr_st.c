#include<stdio.h>
#include<stdbool.h>
#define n 10

int st[n];
int top = -1;

bool is_empty(){
    return top == -1 ? 1 : 0;
}

bool is_full(){
    return top == n-1 ? 1 : 0;
}

void push(int x){
    top++;
    st[top] = x;
}

void pop(){
    st[top] = 0;
    top--;
}

int TOP(){
    return st[top];
}

void print(){
    for(int i = 0; i<= top;i++){
        printf("%d ", st[i]);
    }
}


void main(){
    int str[] = {10, 20, 30, 40, 50};
    int m = sizeof(str)/ sizeof(str[0]);
    for(int i = 0; i< m; i++){
        push(str[i]);
    }
    int str2[m];
    for(int i = 0; i< m; i++){
        str2[i] = TOP();
        pop();
    }
    for(int i = 0; i< m ;i++){
        printf("%d ", str2[i]);
    }
}