#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL, *temp, *newnode;

node* createNode(int);
void print(node*);
void sortLL(node*);


void main(){
    createNode(5);
    sortLL(head);
    print(head);
}

node* createNode(int n){
    head = NULL;
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
    return head;
}

void print(node* head){
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void sortLL(node* head){
    temp = head;
    node *temp1;
    while(temp->next != NULL){
        temp1 = temp->next;
        while(temp1 != NULL){
            if(temp->data > temp1->data){
                int c = temp->data;
                temp->data = temp1->data;
                temp1->data = c;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    
}
