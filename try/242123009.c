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

void pop(){
    if(is_empty()){
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
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
    int N;
    printf("Enter the length of the array: ");
    scanf("%d", &N);
    int A[N];
    printf("Enter the elements of the Array\n");
    for(int i = 0; i< N; i++){
        A[i] = i + 1;
    }
    int B[N];
    for(int i = 0; i< N; i++){
        scanf("%d", &B[i]);
    }
    int i = 0, j = 0;
    int a;
    for(int i = 0; i< N; i++){
        a = B[i];
        while(TOP() != a){
            if(j>=N){
                printf("Not stack-generatable\n");
                return;
            }
            push(A[j]);
            A[j] = 0;
            j++;
        }
        if (j >= N && TOP() != a) {
            printf("Not stack-generatable\n");
            return;
        }
        pop();
    }
    if((is_empty())){
        printf("stack-generatable\n");
    }
    else{
        printf("Not stack-generatable\n");
    }
}