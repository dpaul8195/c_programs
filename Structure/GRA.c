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
    int x = s->st[s->top];
    return x;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}


void main(){
    stack s;
    s.top = -1;
    int arr[] = {3, 5, 1, 7, 5, 9};
    int m = sizeof(arr) / sizeof(arr[0]);

    //NSE
    push(&s, -1);
    int next[m];
    for(int i = m - 1; i >= 0; i--){
        while(TOP(&s) != -1 && arr[TOP(&s)] > arr[i]){
            pop(&s);
        }
        next[i] = TOP(&s);
        push(&s, i);
    }
    

    //PSE
    while(!is_empty(&s)){
        pop(&s);
    }
    push(&s, -1);
    int prev[m];
    for(int i = 0; i < m; i++){
        while(TOP(&s) != -1 && arr[i] < arr[TOP(&s)]){
            pop(&s);
        }
        prev[i] = TOP(&s);
        push(&s, i);
    }

    //GRA
    int area = 0;
    int l,b;
    for(int i = 0; i < m; i++){
        l = arr[i];
        if(next[i] == -1){
            next[i] = m;
        }
        b = next[i] - prev[i] - 1;
        area = max(area, l*b);
    }
    printf("%d", area);
}