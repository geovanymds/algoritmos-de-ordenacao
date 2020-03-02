#include <stdio.h>
#include <stdlib.h>
#include "insercao.h"

void inserctionSort(int *v, int tam,double *TeC){
    
    int marcador,aux,pos;
    
    for(marcador = 1; marcador<tam; marcador++){
        pos = marcador - 1;
        aux = v[marcador];
        
        while ((pos>=0)&&(aux<v[pos])){//busca na parte ordenada a posição correta do elemento no marcador
            //incrementa comparações
            TeC[1]+=1.0;
            //incrementa trocas
            TeC[0]+=1.0;
            v[pos+1] = v[pos];  
            pos--;
        }//deixa o pos no primeiro elemento menor que o do marcador 
        v[pos+1] = aux;
        //incrementa trocas
        TeC[0]+=1.0;
    }
}