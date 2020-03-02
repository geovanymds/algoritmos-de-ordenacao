#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"

void mergeSort(int *v, int inicio, int fim,double *TeC){
    
    int meio;
    
    /*variável responsável por identificar o meio do vetor e dividi-lo*/
    meio = (inicio+fim)/2;
    
    if (inicio < fim) {
        mergeSort(v, inicio, meio,TeC);
        mergeSort(v, meio+1, fim,TeC);
        merge(v,inicio,meio,fim,TeC);
    }
}
void merge(int *v, int inicio, int meio, int fim,double *TeC){
    
    int ini1 = inicio;
    int ini2 = meio + 1;
    int *vAux, tam, i;
    tam = fim - inicio + 1;
    
    /*vetor auxiliar que recebe os elementos de forma ordenada*/
    vAux = (int*)malloc(tam*sizeof(int));
    
    i=0;
    
    /*Comparações para gerar um vetor auxiliar ordenado*/
    while((ini1<=meio)&&(ini2<=fim)){
        //incrementa comparações
        TeC[1]+=1.0;
        if(v[ini1]<=v[ini2]){
            vAux[i] = v[ini1];
            ini1++;
        }
        else{
            vAux[i] = v[ini2];
            ini2++;
            //incrementa trocas
            TeC[0]+=1.0;
        }
        i++;
    }
    /*o primeiro vetor ainda não foi totalmente alocado no auxiliar*/
    while(ini1<=meio){
        vAux[i] = v[ini1];
        i++;
        ini1++;
    }
    /*o segundo vetor ainda não foi totalmente alocado no auxiliar*/
    while(ini2<=fim){
        vAux[i] = v[ini2];
        i++;
        ini2++;
    }
    
    i=0;
    /*aqui ini1 recebe o inicio recebido pela função.
     a finalidade é economizar variáveis*/
    ini1 = inicio;
    /*passando o vetor auxiliar para o original*/
    while(ini1<=fim){
        v[ini1] = vAux[i];
        ini1++;
        i++;
    }
    
    /*liberando o vetor auxiliar da memória*/
    free(vAux);
}

void mergeSortInverso(int *v, int inicio, int fim){
    
    int meio;
    
    /*variável responsável por identificar o meio do vetor e dividi-lo*/
    meio = (inicio+fim)/2;
    
    if (inicio < fim) {
        mergeSortInverso(v, inicio, meio);
        mergeSortInverso(v, meio+1, fim);
        mergeInverso(v,inicio,meio,fim);
    }
}
void mergeInverso(int *v, int inicio, int meio, int fim){
    
    int ini1 = inicio;
    int ini2 = meio + 1;
    int *vAux, tam, i;
    tam = fim - inicio + 1;
    
    /*vetor auxiliar que recebe os elementos de forma ordenada*/
    vAux = (int*)malloc(tam*sizeof(int));
    
    i=0;
    
    /*Comparações para gerar um vetor auxiliar ordenado*/
    while((ini1<=meio)&&(ini2<=fim)){
        if(v[ini1]>=v[ini2]){
            vAux[i] = v[ini1];
            ini1++;
        }
        else{
            vAux[i] = v[ini2];
            ini2++;
        }
        i++;
    }
    /*o primeiro vetor ainda não foi totalmente alocado no auxiliar*/
    while(ini1<=meio){
        vAux[i] = v[ini1];
        i++;
        ini1++;
    }
    /*o segundo vetor ainda não foi totalmente alocado no auxiliar*/
    while(ini2<=fim){
        vAux[i] = v[ini2];
        i++;
        ini2++;
    }
    
    i=0;
    /*aqui ini1 recebe o inicio recebido pela função.
     a finalidade é economizar variáveis*/
    ini1 = inicio;
    /*passando o vetor auxiliar para o original*/
    while(ini1<=fim){
        v[ini1] = vAux[i];
        ini1++;
        i++;
    }
    
    /*liberando o vetor auxiliar da memória*/
    free(vAux);
}