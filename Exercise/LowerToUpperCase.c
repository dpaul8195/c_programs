#include<stdio.h>

int len(char s[]){
    int i = 0;
    char a = s[i];
    while(a != '\0'){
        i++;
        a = s[i];
    }
    return i;
}

void main(){
    char s[50];
    printf("Enter your string in lower Case: ");
    gets(s);
    int n = len(s);
    char S[n];
    for(int i = 0; i<n; i++){
        S[i] = s[i] - 32;
    }
    S[n] = '\0';
    printf("Your string in upper case is %s", S);
}