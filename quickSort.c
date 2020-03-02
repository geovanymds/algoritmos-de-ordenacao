#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

void quickSort(int *v, int inicio, int fim,double *TeC){
    
    int pivo;
    
    /*quando se está no vetor unitário não é necessário ordenar*/
    if (inicio<fim){
        pivo = particiona (v,inicio,fim,TeC);
        quickSort(v,inicio,pivo-1,TeC);
        quickSort(v,pivo+1,fim,TeC);
    }
}

int particiona(int *v, int inicio, int fim,double *TeC){
    int i,pivo,pos,aux;
    pivo = v[inicio];
    pos = inicio;
    
    /*função para encontrar a posição correta do pivo no vetor*/
    for(i=inicio+1;i<=fim;i++){
        //incrementa comparações
        TeC[1]+=1.0;
        if(v[i]<pivo){
            pos++;
            if(i!=pos){
                aux = v[pos];
                v[pos] = v[i];
                v[i] = aux;
                //incrementa trocas
                TeC[0]+=1.0;
            }
        }
    }
    
    //incrementa trocas
    TeC[0]+=1.0;
    aux = v[inicio];
    v[inicio] = v[pos];
    v[pos] = aux;
    
    return(pos);
}

