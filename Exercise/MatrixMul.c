#include<stdio.h>

void main(){
    int a[2][4],b[4][2];
    int sum;
    int result[2][2];
    for(int i = 0; i<2;i++){
        for(int j = 0; j<4;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i<4;i++){
        for(int j = 0; j<2;j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0;i<2;i++){
        for(int j = 0; j<2;j++){
            sum = 0;
            for(int k = 0;k<4;k++){
                sum = sum + a[i][k]*b[k][j];
            }
            result[i][j] = sum;
        }
    }
}