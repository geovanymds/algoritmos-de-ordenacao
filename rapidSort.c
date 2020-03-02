#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rapidSort.h"

void rapidSort(int *v,int tam,double *TeC){
    //variáveis
    int i,aux,pos=0;
    //marcadores iniciados no começo e no fim do vetor
    int lowBound = 0;
    int upBound = tam-1;
    //coloca o maior elemento no final
    for(i=1;i<tam;i++){   
        //incrementa comparações
        TeC[1]+=1.0;
        if(v[i]>v[pos])
        {
            //posição do maior elemento
            pos = i;
        }
    }
    aux = v[pos];
    v[pos] = v[tam-1];
    v[tam-1] = aux;
    pos=0;
    //coloca o menor elemento no começo
    for(i=1;i<tam;i++){
        //incrementa comparações
        TeC[1]+=1.0;
        if(v[i]<v[pos])
        {
            //posição do menor elemento
            pos = i;
        }
    }
    aux = v[pos];
    v[pos] = v[0];
    v[0] = aux;
    while((upBound-lowBound)>1){
        //verifica se o valor está mais próximo do maior ou do menor
        if(abs(v[lowBound]-v[lowBound+1])<abs(v[upBound]-v[lowBound+1])){
            //incrementa comparações
            TeC[1]+=1.0;
            if(v[lowBound+1]<v[lowBound]){
                //incrementa comparações
                TeC[1]+=1.0;
                aux = v[lowBound+1];
                i = lowBound;
                while ((i>=0)&&(aux<v[i])){
                    v[i+1] = v[i];  
                    i--;
                    //incrementa trocas
                    TeC[0]+=1.0;
                }
                v[i+1] = aux;                
            }
            lowBound++;
        }
        else{
            //troca o lowBound+1 com o upBound-1
            aux = v[lowBound+1];
            v[lowBound+1] = v[upBound-1];
            v[upBound-1] = aux;
            //incrementa trocas
            TeC[0]+=1.0;
            //acha a posição correta do elemento na parte com maiores elementos
            if(v[upBound-1]>v[lowBound]){
                //incrementa comparações
                TeC[1]+=1.0;
                aux = v[upBound-1];
                i = upBound;
                while ((i<=tam)&&(aux>v[i])){
                    v[i-1] = v[i];  
                    i++;
                    //incrementa trocas
                    TeC[0]+=1.0;
                }
                v[i-1] = aux;
                //incrementa trocas
                TeC[0]+=1.0;
            }
            upBound--;
        }
                
    }
    
}


