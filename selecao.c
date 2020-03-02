#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"

void selectionSort(int *vetor, int tam,double *TeC){
    //marcador dos elementos ordenados e variável para o menor número
    int marcador,menor,i;
    
    marcador = 0;   
    
    while (marcador < tam-1) {
        
        /*o menor valor da parte desordenada vai ser encontrada a partir
         da posição próxima ao marcador*/
        menor = marcador +1;
        /*encontra o menor elemento da parte desordenada*/
        for(i = menor+1; i<tam; i++){
            //incrementa comparações
            TeC[1]+=1.0;
            if(vetor[menor]>vetor[i]){
                menor = i;
            }
        }
        /*troca os elementos caso o valor de menor seja menor que o valor no 
        marcador e usa i como auxiliar, já que ele é setado em 1, em cada volta*/
        if (vetor[menor]<vetor[marcador]){
            //incrementa comparações
            TeC[1]+=1.0;
            //incrementa trocas
            TeC[0]+=1.0;
            i = vetor[marcador];
            vetor[marcador] = vetor[menor];
            vetor[menor] = i;
        }
        marcador ++;
    }    
}

