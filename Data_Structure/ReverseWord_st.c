#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
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
    char str[] = "Hello World"; 
    int m = sizeof(str)/ sizeof(str[0]);
    for(int i =0; i< m; i++){
        if(str[i]!= ' '){
            push(str[i]);
        }
        else{
            while(!is_empty()){
                printf("%c ", TOP());
                pop();
            }
        }
    }
    while(!is_empty()){
                printf("%c ", TOP());
                pop();
            }
}