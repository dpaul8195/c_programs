#include<stdio.h>
#include<stdbool.h>
#define n 10

char st[n];
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

char TOP(){
    if(is_empty()){
        // printf("Stack is empty");
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
    char arr[] = "([";
    int m = 6;
    bool wrong = false;
    int i = 0;
    while(i< m && wrong == false){
        if((arr[i]=='(') || (arr[i]=='{') || (arr[i]=='[')){
            push(arr[i]);
        }else{
            switch (arr[i]){
                case ')':
                    if(TOP() == '('){
                        pop();
                    }
                    else{
                        wrong = true;
                    }
                    break;
                case '}':
                    if(TOP() == '{'){
                        pop();
                    }
                    else{
                        wrong = true;
                    }
                    break;
                case ']':
                    if(TOP() == '['){
                        pop();
                    }
                    else{
                        wrong = true;
                    }
                    break;
            }
        }
        i++;
    }

    if(is_empty() && wrong == false)
    {
        printf("Balanced");
    }
    else{
        printf("Unbalanced");
    }
}