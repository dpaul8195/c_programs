#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL, *tail, *newnode, *temp;

void createList(int);
void printF(node*);
void printB(node*);

void main(){
    createList(4);
    printF(head);
    printf("\n");
    printB(tail);
}

void createList(int n){
    for(int i = 0; i< n; i++){
        newnode = (node*)malloc(sizeof(node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            newnode->prev = NULL;
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void printF(node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void printB(node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->prev;
    }
}