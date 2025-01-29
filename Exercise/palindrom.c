#include<stdio.h>
#include<stdbool.h>

int len(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

bool palindrom(char s[]){
    int n = len(s);
    int i = 0;
    int j = n -1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void main(){
    char s[50];
    printf("Enter your string: ");
    gets(s);
    if(palindrom(s)){
        printf("It is palindrom");
    }
    else{
        printf("It is not a palindrom");
    }
}