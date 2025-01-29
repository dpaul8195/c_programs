#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head, *newnode, *temp;

void enqueue(int x);
int dequeue();
int is_empty();
void display(node *);

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display(head);
    printf("\n");
    dequeue();
    dequeue();
    dequeue();
    display(head);
}

void enqueue(int x){
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}

int dequeue(){
    if(is_empty()){
        return -1;
    }
    if(head->next == NULL){
        temp = head;
        int x = temp->data;
        head =  NULL;
        free(temp);
        return x;
    }
    else{
        temp = head;
        int x = head->data;
        head = head->next;
        free(temp);
        return x;
    }
}

int is_empty(){
    return head == NULL;
}

void display(node *head){
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}