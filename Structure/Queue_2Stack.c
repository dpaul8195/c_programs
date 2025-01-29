#include<stdio.h>
#define n 10
typedef struct stack{
    int top;
    int st[n];
}stack;

int is_empty(stack *s){
    return s->top == -1;
}

int is_full(stack *s){
    return s->top == n-1;
}

void push(stack *s, int x){
    if(is_full(s)){
        return;
    }
    s->top++;
    s->st[s->top] = x;
}

void pop(stack *s){
    if(is_empty(s)){
        return;
    }
    s->top--;
}

int TOP(stack *s){
    if(is_empty(s)){
        return -1;
    }
    return s->st[s->top];
}

void display(stack *s){
    for(int i = 0; i<= s->top; i++){
        printf("%d ", s->st[i]);
    }
}

//queue
stack s1;
stack s2;
int front = -1, rear = -1;


int isEmpty(){
    return is_empty(&s1);
}

int isFull(){
    return is_full(&s1);
}

void enqueue(int x){
    if(isFull()){
        return;
    }
    if(isEmpty()){
        front = rear = 0;
        push(&s1, x);
    }
    else{
        front++;
        push(&s1, x);
    }
}

int dequeue(){
    while(!is_empty(&s1)){
        int x = TOP(&s1);
        pop(&s1);
        push(&s2, x);
    }
    int y = TOP(&s2);
    pop(&s2);
    while(!is_empty(&s2)){
        int x = TOP(&s2);
        pop(&s2);
        push(&s1, x);
    }
    front++;
    return y;
}


void main(){
    s1.top = -1;
    s2.top = -1;
    enqueue(2);
    enqueue(3);
    enqueue(5);
    dequeue();
    display(&s1);
}