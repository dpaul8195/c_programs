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

void display(stack *s){
    for(int i = 0; i<= s->top; i++){
        printf("%d ", s->st[i]);
    }
}

void main(){
    stack s;
    s.top = -1;
    push(&s, 3);
    push(&s, 8);
    push(&s, 9);
    push(&s, 8);
    pop(&s);
    display(&s);
}