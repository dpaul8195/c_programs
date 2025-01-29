#include<stdio.h>
#include<stdlib.h>

void merge(int*, int, int, int);

void main(){
    int n;
    printf("Enter the length of the array ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements\n");
    for(int i = 0; i< n; i++){
        scanf("%d", &A[i]);
    }
    merge(A, 0, n/2, n);
    for(int i = 0; i< n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int* A, int p, int q, int r){
    int nl = q - p + 1;
    int nr = r - q;
    if(p >= r)return;
    merge(A, p, (p + q)/ 2, q);
    merge(A, q + 1, (q + r)/ 2, r);
    int *L = (int*)malloc(sizeof(int) * nl);
    int *R = (int*)malloc(sizeof(int) * nr);
    for(int i = 0; i< nl; i++){
        L[i] = A[p + i];
    }
    for(int i = 0; i< nr; i++){
        R[i] = A[q + i + 1];
    }

    int i = 0, j = 0, k = p;
    while(i < nl && j < nr){
        if(L[i] < R[j]){
            A[k++] =  L[i++];
        }
        else{
            A[k++] = R[j++];
        }
    }
    while(i < nl){
        A[k++] = L[i++];
    }
    while(j < nr){
        A[k++] = R[j++];
    }
    free(L);
    free(R);
}