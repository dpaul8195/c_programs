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

int len(char arr[]){
    int count = 0;
    while(arr[count] != '\0'){
        count++;
    }
    return count;
}

void main(){
    char str[50];
    printf("Enter Your String: ");
    gets(str);
    int m = len(str);
    for(int i = 0; i< m; i++){
        push(str[i]);
    }
    char str2[20];
    for(int i = 0; i< m; i++){
        str2[i] = TOP();
        pop();
    }
    printf("Reverse String is ");
    for(int i = 0; i< m ;i++){
        printf("%c", str2[i]);
    }
}