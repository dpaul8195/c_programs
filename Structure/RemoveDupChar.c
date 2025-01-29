#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* next;
}node;

node *newnode, *head = NULL, *temp;

void push(char x){
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

char pop(){
    temp = head->next;
    char x = head->data;
    free(head);
    head = temp;
    return x;
}

int is_empty(){
    return head==NULL;
}

void print(){
    temp = head;
    while(temp != NULL){
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

void main(){
    char s[50];
    printf("Enter String: ");
    gets(s);
    int i = 0;
    while(s[i] != '\0'){
        if(is_empty()){
            push(s[i++]);
        }
        else{
            char x = pop();
            if(x == s[i]){
                i++;
                continue;
            }
            else{
                push(x);
                push(s[i++]);
            }
        }
    }
    print();   
}