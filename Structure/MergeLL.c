#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head, *temp, *newnode;

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

node* mergeLL(node *L1, node *L2){
    node* H, *P;
    if(L1 == NULL){
        return L2;
    }
    if(L2  == NULL){
        return L1;
    }
    if(L1->data < L2->data){
        H = L1;
        P = L1;
        L1 = L1->next;
    }
    else{
        P = L2;
        H = L2;
        L2 = L2->next;
    }
    while(L1 != NULL && L2 != NULL){
        if(L1->data < L2->data){
            P->next = L1;
            L1 = L1->next;
            P = P->next;
        }
        else{
            P->next = L2;
            L2 = L2->next;
            P = P->next;
        }
    }
    if(L1 != NULL){
        P->next = L1;
    }
    else{
        P->next = L2;
    }
    return H;
}

void main(){
    node* head1 = createNode(3);
    node* head2 = createNode(3);
    sortLL(head1);
    printf("Sorted List1\n");
    print(head1);
    sortLL(head2);
    printf("\nSorted List2\n");
    print(head2);
    node* Head = mergeLL(head1, head2);
    printf("\nMerged List\n");
    print(Head);
}