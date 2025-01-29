#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL, *newnode,*temp;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int arr[], int n){
    for(int i= 0; i<n -1; i++){
        int temp = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[temp]){
                temp = j;
            }
        }
        swap(&arr[i], &arr[temp]);
    }
}

node* createNode(int arr[], int n){
    sort(arr, n);
    head = NULL;
    for(int i = 0; i<n ; i++){
        newnode = (node*)malloc(sizeof(node));
        newnode->data = arr[i];
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void print(node *head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

node* insert(node *head, node *newnode){
    temp = head;
    node *prev;
    while(temp->data < newnode->data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        newnode->next = head;
        head = newnode;
        return head;
    }
    prev->next = newnode;
    newnode->next = temp;
    return head;
}

node* merge(node *p1, node *p2){
    while(p2!=NULL){
        p1 = insert(p1,p2);
        p2 = p2->next;
    }
    return p1;
}

void main(){
    int A[] = {2,6,4,8};
    int B[] = {3,1,7,5};
    node *head1 = createNode(A, 4);
    node *head2 = createNode(B, 4);
    print(head1);
    printf("\n");
    print(head2);
    merge(head1, head2);
    print(head);
}