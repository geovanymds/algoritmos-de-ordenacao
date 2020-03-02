#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arquivo.h"

void geraArquivoAleatorio(int tam, char nome[]){
    
    //índice, tamanho do arquivo e arquivo
    int i;
    FILE *arq;
    
    //abrindo o arquivo
    arq = fopen (nome,"w");
    
    //verificando se o arquivo foi aberto
    if(!arq){
        printf("O arquivo não pôde ser aberto.\n");
        exit (1);
    }
    
    //gerando a semente para números aleatórios com base no relógio do SO
    srand(time(NULL));
    
    //preenchendo o arquivo
    for (i=0; i<=tam; i++){
        fprintf(arq,"%d\r\n", rand() % tam);
    }
    
    printf("Arquivo gerado !\n");
    
    fclose(arq);
    
    return;
}
void lerArquivo(int* v, int tam, char nome[]){
    
    //variáveis
    int i;
    FILE *arq;
    arq = fopen(nome,"r");
    
    //verificação 
    if(!arq){
        printf("O arquivo não pôde ser aberto.\n");
        exit(1);
    }    
    
    //preencher vetor com valores do arquivo
    for (i=0; i<tam; i++){
        fscanf(arq,"%d\r\n", &v[i]);
    }  
    
    printf("O arquivo foi aberto.\n");
    
    fclose(arq);
    
    return;
}
void mostrarArquivo(int tam){
    
    //variáveis
    int i,valor;
    FILE *arq;
    arq = fopen("entrada.txt","r");
    
    //verificação 
    if(!arq){
        printf("O arquivo não pôde ser aberto.\n");
        exit(1);
    }    
    
    //aloca o valor na na variável e imprime
    for (i=0; i<tam; i++){
        fscanf(arq,"%d ", &valor);
        printf("%d ",valor);
    }
    printf("\n");
    
    fclose(arq);
}
void criaNomeArquivo (int tam, int indice, char nomeArq[]){
	int j;
	char resultado[3];
	memset(resultado, 0, sizeof(resultado));
	j = sprintf(nomeArq, "%d", tam);
	strcat(nomeArq, "\\");
	j = sprintf(resultado, "%d", indice);
	strcat(nomeArq, resultado);
	strcat(nomeArq, ".txt");
}
void gravaArquivo(int *v,int tam,char nome[]){
    
    int i;
    
    FILE *arq;
    
    arq = fopen(nome,"w");
    
    if(!arq){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    
    for(i=0; i<tam; i++){
        fprintf(arq,"%d\r\n",v[i]);
    }
    
    fclose(arq);
}
