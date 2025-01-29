#include<stdio.h>
#include<stdlib.h>


int main(){

    
    FILE *fp = fopen("abc.txt", "w");
    if(fp == NULL){
        printf("Error!");
        exit(1);
    }
    char str[] = "kjgojsjgg";
    fputs(str, fp);

    fclose(fp);
    return 0;
}