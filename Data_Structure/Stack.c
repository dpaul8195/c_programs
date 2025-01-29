#include<stdio.h>
#include<stdbool.h>
#define n 10

int st[n];
int top = -1;

bool is_empty()
{
    if(top == -1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool is_full()
{
    if(top == n-1)
    {
        return true;
    }
    else{
        return false;
    }
}

void push(int x){
    if(is_full()){
        printf("Stack is full");
    }
    else{
        top ++;
        st[top] = x;
    }
}

int TOP(){
    if(is_empty()){
        printf("Stack is empty");
        return 0;
    }
    else{
        return st[top];
    }
}

void pop()
{
    if(is_empty()){
        printf("Stack is empty");
    }
    else{
        st[top]= 0;
        top--;
    }
}

void print(){
    for(int i = 0; i<= top; i++)
    {
        printf("%d ", st[i]);
    }
}

void main()
{
    push(5);
    push(8);
    push(5);
    push(8);
    push(9);
    print();
    printf("\n");
    pop();
    print();
}