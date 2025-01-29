#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define n 20

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
        return 0;
    }
    else{
        return st[top];
    }
}

void pop()
{
    if(is_empty()){
        int x;
    }
    else{
        st[top]= 0;
        top--;
    }
}

int priority(char a){
    if((a=='^')) return 3;
    else if((a=='*') || (a == '/') || (a == '%')) return 2;
    else if((a=='+') || (a == '-')) return 1;
    else return 0;
}

void main()
{
    char infix[50] = "4^2*3-3+8/4/(1+1)";
    char postfix[50];
    int i = 0;
    int j = 0;
    char s = infix[i];
    while(s != '\0')
    {
        if(isdigit(s))
        {
            postfix[j++] = s;
        }
        if(s=='('){
            push(s);
        }
        if(s=='^' || s=='*' || s=='/'|| s== '+' || s=='-' || s=='%'){
            if(is_empty()){
                push(s);
            }
            else{
                while(priority(TOP()) >= priority(s)){
                    postfix[j++] = TOP();
                    pop();
                }
                push(s);
            }
        }
        if(s==')'){
            while(TOP()!='('){
                postfix[j++] = TOP();
                pop();
            }
            pop();
        }
        i++;
        s = infix[i];
    }
    while(!is_empty())
    {
        postfix[j++] = TOP();
        pop();
    }

    postfix[j] = '\0';
    printf("%s", postfix);
}