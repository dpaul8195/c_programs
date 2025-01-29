#include<stdio.h>

void main(){
    char s[50];
    printf("Enter your email: ");
    gets(s);
    
    int i = 0;
    char a = s[i];
    while(a != '@'){
        a = s[++i];
    }
    char s1[50];
    for(int j = 0; j< i;j++){
        s1[j] = s[j];
    }
    s1[i] = '\0';
    printf("Your username is %s", s1);
}