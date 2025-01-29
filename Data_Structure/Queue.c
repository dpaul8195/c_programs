#include<stdio.h>
#include<stdbool.h>
#define n 10

int q[n];
int rear = -1;
int front = -1;

bool is_empty(){
    return( rear == -1 && front == -1);
}

bool is_full(){
    return (rear + 1) % n == front;
}

void enqueue(int x){
    if(is_full()){
        printf("full");
        return;
    }
    if(is_empty()){
        front = rear = 0;
        q[rear] = x;
    }
    else{
        rear = (rear + 1)%n;
        q[rear] = x;
    }
}

void dequeue(){
    if(is_empty()){
        printf("Empty");
        return;
    }
    if(rear == front){
        front = rear = -1;
    }
    else{
        front = (front + 1)%n;
    }
}

int peak(){
    return q[front];
}

void display(){
    int i = front;
    while(i != rear){
        printf("%d ",q[i]);
        i = (i +1)%n;
    }
    printf("%d ", q[i]);
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // display();

    dequeue();
    dequeue();

    // display();

    int x = peak();
    printf("front is %d", x);

    enqueue(60);
    display();
}