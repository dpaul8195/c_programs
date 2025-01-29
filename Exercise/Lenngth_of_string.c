#include<stdio.h>

int len(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void main(){
    // char name[] = "Papai Paul";
    char str[100];
    gets(str);
    int x = len(str);
    printf("%d", x);
}