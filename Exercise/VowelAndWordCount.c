#include<stdio.h>

int countv(char *s){
    int i = 0;
    int count = 0;
    char a = s[i];
    while(a != '\0'){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            count++;
        }
        a = s[++i];
    }
    return count;
}

int countw(char *s){
    int i = 0;
    int count = 0;
    char a = s[i];
    while(a != '\0'){
        if(a == ' '){
            count++;
        }
        a = s[++i];
    }
    return count;
}

void main(){
    char *s = "enter your string in upperCase";
    printf("Number of vowels is %d\n",countv(s));
    printf("Number of words is %d",countw(s) +1);
}