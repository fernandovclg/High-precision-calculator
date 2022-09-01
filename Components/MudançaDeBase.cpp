#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define tamStr 100

using namespace std;

int logInt(int x , int n ){
    int i=0, aux=1;
    while(aux <= x){
        aux=n*aux;
        i++;
    }
    return i-1;
}

int* baseN(int x , int n ){
    int L = logInt(x , n ) , aux;
    int *num = (int*)malloc(   sizeof(int)   ) ;
    for(int i = 0; i<L;i++){
        num[i] = x % n;
        x= x/n;
    };
    return num;
}



int main(){
    int numero =61,
        base = 2;
    int *num=baseN(numero,base);
    for(int i = 0; i<logInt(numero,base);i++){
        cout << num[i]<<endl;
    }
    return 0;
}