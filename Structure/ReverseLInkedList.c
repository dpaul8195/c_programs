#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL, *newnode, *temp;

void createNode(int);
void print();
void reverse();

void main(){
    createNode(3);
    print();
    reverse();
    print();
}

void createNode(int n){
    for(int i = 0;i<n; i++){
        newnode = (node*)malloc(sizeof(node));
        if(head == NULL){
            head = newnode;
        }else{
            temp->next = newnode;
        }
        printf("Enter Data: ");
        scanf("%d", &(newnode->data));
        newnode->next = NULL;
        temp = newnode;
    }
}

void print(){
    temp = head;
    printf("Your Data is: \n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverse(){
    node *prevnode, *nextnode;
    prevnode = NULL;
    temp = nextnode = head;
    while(nextnode != NULL){
        nextnode = nextnode->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    head = prevnode;
}