#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL, *newnode, *temp;

int is_empty(){
    return head == NULL;
}

void push(int x){
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

int pop(){
    if(is_empty()){
        return -1;
    }
    temp = head;
    int x = temp->data;
    head = head->next;
    free(temp);
    return x;
}

int TOP(){
    if(is_empty()){
        return -1;
    }
    return head->data;
}

void display(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void main(){
    push(5);
    push(4);
    push(3);
    display(head);
}