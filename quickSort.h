#ifndef QUICKSORT_H
#define QUICKSORT_H

/*função recursiva para dividir o vetor*/
void quickSort(int *v, int inicio, int fim,double *TeC);
/*função que coloca o vetor o pivo na posicção correta
 do vetor ou sub vetor*/
int particiona(int *v, int inicio, int fim,double *TeC);

#endif /* QUICKSORT_H */

