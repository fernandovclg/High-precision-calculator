#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define tamStr 100

using namespace std;

class num {
    public:
        int *array;
        int tamanho;
        bool sinal;
};


char* newNumber(){
    char numero[tamStr];
    printf("digite um numero inteiro: ");
    scanf("%s",numero);
    int i=0;
    while(numero[i]!=NULL){
        if(numero[i]<48 || numero[i]>57){
            printf("not an integer\n");
            return NULL;
        }
        i++;
    }
    char *num = (char*)malloc(   (i+1) * sizeof(char)   ) ;
    int j=0;
    while(j<=i){
        num[j]=numero[j];
        j++;
    }

    return num;
}

void imprimirNum(char * num){
    int i=0;
    while(num[i]!=NULL){
        printf("%c",num[i]);
        i++;
    }
    printf("\n");
}



int main(){
    char *num1,*num2;
    num1= newNumber();
    imprimirNum(num1);
    num2= newNumber();
    imprimirNum(num2);    
    return 0;
}