#include<iostream>
using namespace std;

void display(int a[3][2]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j< 2; j++){
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int a[3][2];
    
    display(a);


    return 0;
}