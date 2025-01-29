#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *head = NULL, *newnode, *temp;

void push(int);
int pop();
int is_empty();
int top();
void display(node*);
void removeMiddle(node*,int, int);
int len(node*);

void main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int n = len(head);
    removeMiddle(head,0, n);
    display(head);
}

void push(int x){
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if(is_empty()){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int pop(){
    if(is_empty()){
        return -1;
    }
    if(head->next == NULL){
        temp = head;
        head = NULL;
        free(temp);
        return -1;
    }
    else{
        temp = head;
        node *prev = head;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        int x = temp->data;
        free(temp);
        prev->next = NULL;
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

int len(node *head){
    int count = 0;
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

void removeMiddle(node *head, int count, int n){
    if(count == n /2){
        pop();
        return;
    }
    int x = pop();
    removeMiddle(head, count+1, n);
    push(x);
}