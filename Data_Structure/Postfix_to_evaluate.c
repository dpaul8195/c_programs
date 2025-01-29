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
    char postfix[20];
    printf("Enter postfix expression ");
    gets(postfix);
    int x, y;
    int m = sizeof(postfix) / sizeof(postfix[0]);
    for(int i = 0; i< m; i++){
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            switch (postfix[i]){
                case '+':
                    x = TOP();
                    pop();
                    y = TOP() + x;
                    pop();
                    push(y);
                    break;
                case '-':
                    x = TOP();
                    pop();
                    y = TOP() - x;
                    pop();
                    push(y);
                    break;
                case '*':
                    x = TOP();
                    pop();
                    y = TOP() * x;
                    pop();
                    push(y);
                    break;
                case '/':
                    x = TOP();
                    pop();
                    y = TOP() / x;
                    pop();
                    push(y);
                    break;
            }
        }
    }
    printf("Result is %d", TOP());
}