#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define n 10

int st[n][n];
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

void push(int x[]){
    if(is_full()){
        printf("Stack is full");
    }
    else{
        top ++;
        strcpy(st[top],x);
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

void main()
{
    char s[] = "42$3*3-84/11+/+";
    int m = 15;
    int i = 0;
    while(i<m){
        if(isdigit(s[i])){
            char temp[] = {s[i]};
            push(temp);
        }
        else{
            char t1[] = {TOP()};
            pop();
            char t2[] = {TOP()};
            pop();
            char temp[] = {s[i]};
            char con[50];
            strcpy(con,t2);
            strcat(con,temp);
            strcat(con,t1);
            push(con);
        }
        i++;
    }
}