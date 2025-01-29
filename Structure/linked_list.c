#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL, *newnode, *temp;

void createNode(int);
void print();
int count();
void insertFirst();
void insertLast();
void insertAt(int);
void deleteFirst();
void deleteLast();
void deleteAt(int);

void main(){
    createNode(4);
    print();
    deleteAt(2);
    printf("\n");
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

int count(){
    if(head == NULL){
        return 0;
    }
    temp = head;
    int i = 1;
    while(temp->next != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

void insertFirst(){
    newnode = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertLast(){
    newnode = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAt(int n){
    int m = count();
    if(n > m){
        printf("Can't possible");
    }
    else{
        newnode = (node*)malloc(sizeof(node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        temp = head;
        int i = 1;
        while(i < n){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteFirst(){
    temp = head;
    head = head->next;
    free(temp);
}

void deleteLast(){
    if(head == NULL){
        printf("No Linked list is there");
        return;
    }
    node *prev;
    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = NULL;
    }
    else{
        prev->next = NULL;
    }
    free(temp);
}

void deleteAt(int n){
    int m = count();
    if(n > m){
        printf("Endex Error");
        return;
    }
    int i = 1;
    temp = head;
    while(i < n - 1){
        temp = temp->next;
        i++;
    }
    node *nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}