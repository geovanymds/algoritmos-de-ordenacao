
#ifndef MERGESORT_H
#define MERGESORT_H

/*função responsável por dividir o vetor*/
void mergeSort(int *v, int inicio, int fim,double *TeC);
/*função responsável por ordenar as divisões do vetor*/
void merge(int *v, int inicio, int meio, int fim,double *TeC);


//Funções adaptadas para gerar os arquivos ordenados de forma decrescente
/*função responsável por dividir o vetor*/
void mergeSortInverso(int *v, int inicio, int fim);
/*função responsável por ordenar as divisões do vetor de forma decrescente*/
void mergeInverso(int *v, int inicio, int meio, int fim);

#endif /* MERGESORT_H */

