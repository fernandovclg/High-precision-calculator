#include <stdio.h>
#include <iostream>
#include <math.h>
#define tamStrMax 100

using namespace std;

class Num {
    public:
        unsigned int* value;
        int mantisa;
        bool sign;
        int tamArray;
        Num(char* str);
        void newNum();
        Num sum(Num);
    //metodos 
        unsigned int* valueAccess();
};

Num :: Num(char* str=""){
    int tamStr=0, zerosEsq=0;
    bool unidade=false;
    for(int i=0; str[i]!=NULL;i++ ){
        tamStr++;
        if(str[i]=='0' && !unidade){
            zerosEsq++;
        }
        else{
            unidade=true;
        }
    }
    tamStr = tamStr-zerosEsq;
    tamArray = (tamStr)/9;
    if(tamStr%9 != 0){ tamArray++;}
    printf("tamArray no construtor = %d\n",tamArray);

    
    unsigned int *num = (unsigned int*)calloc( tamArray , sizeof(int)) ;
    
    for(int i=0;i<tamArray;i++){
        for(int j=0;j<9;j++){
            if(tamStr-1-8+j-9*i>=0){
                num[i]=(str[zerosEsq+tamStr-1-8+j-9*i] - 48)+10*num[i];
            }
        }
    }
    value = num;
}

unsigned int* Num:: valueAccess(){
    return value;
}


int Max(int a , int b){
    if (b-a>0) return b;
    else return a;
}

int Min(int a , int b){
    if (b-a>0) return a;
    else return b;
}

Num sum(Num num1 , Num num2){
    int tamMax =Max (num1.tamArray,num2.tamArray);
    printf("tamanho maximo:%d\n",tamMax);
    char *strBase = (char*)malloc( tamMax  * sizeof(char)) ;

    printf("\nstring :%s\n",strBase);
    Num soma(strBase);
    printf("soma dentro:%d",soma.tamArray);
    int i=0;
    while(i<tamMax){
        // printf("\n\n%d => %d\n",i,soma.value[i]);
        soma.value[i]=num1.value[i] + num2.value[i];
        if(soma.value[i]>=1000000000){

            soma.value[i]=soma.value[i]-1000000000;
            if(i<tamMax - 1){
                soma.value[i+1]=soma.value[i+1]+1;
            }
            else{
                soma.value = (unsigned int*)realloc( soma.value ,  (tamMax+1) * sizeof(int)   ) ;
                soma.value[i+1]=1;
                soma.tamArray++;
            }
        }
        i++;
    }
    return soma;
}


int main(){
    char str1[tamStrMax]="2";
    char str2[tamStrMax]="9999999998";
    Num num1(str1);
    Num num2(str2);
    Num Sum;
    Sum = sum(num1,num2);
        printf("\nresultado = %d",Sum.tamArray);
        printf("\nresultado = %d",sum(num1,num2).tamArray);
    for(int i=Sum.tamArray-1;i>=0;i--){
        printf("%d",Sum.value[i]);
    }
        // int *num = newNumber();
    // for(int i=0;i<tam;i++){
    //     cout << num[i]<<endl;
    // }
    return 0;
}