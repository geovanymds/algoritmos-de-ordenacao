#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"
#include "selecao.h"
#include "insercao.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "rapidSort.h"

#define TAM_NOME 17

void menu(int opcao);
int main() {
    
    //variáveis
    int i,j,*v,tam[5] = {10000, 12500, 15000, 20000, 30000};
    char nome[TAM_NOME];
    char dados[14] = "relatorio.txt";
    double k[2];
    
    
    FILE *relatorio;
    
    
    double mediaCopiasDeRegistro;
    double mediacomparacoesDeChaves;
    double mediaTempoDeExecucao;
    double total;
    //vetores com as métricas analisadas vetores aleatórios
    //vetor com cópias de registro
    double copiasDeRegistro1[5];
    //vetor de comparações de chaves
    double comparacoesDeChaves1[5];
    //vetor de tempos de execução milisegundos
    double tempoDeExecucao1[5];
    
    //vetores com as métricas analisadas vetores ordenados crescente
    //vetor com cópias de registro
    double copiasDeRegistro2[5];
    //vetor de comparações de chaves
    double comparacoesDeChaves2[5];
    //vetor de tempos de execução milisegundos
    double tempoDeExecucao2[5];
    
    //vetores com as métricas analisadas vetores ordenados decrescente
    //vetor com cópias de registro
    double copiasDeRegistro3[5];
    //vetor de comparações de chaves
    double comparacoesDeChaves3[5];
    //vetor de tempos de execução milisegundos
    double tempoDeExecucao3[5];
    
    
    //vetor para contar trocas e comparações
    //0 - troca 1 - comparações
    double trocaEComparacao[2];
    
    clock_t ini;
    
    /*GERAR OS ARQUIVOS NA PRIMEIRA EXECUÇÃO
//cria arquivos desordenados
    for(i=0;i<5;i++){
        for(j=1;j<=30;j++){
            criaNomeArquivo(tam[i],j,nome);
            geraArquivoAleatorio(tam[i],nome);
        }
    }
    //cria arquivos crescentes
    j = 31;
    for(i=0;i<5;i++){
        criaNomeArquivo(tam[i],j,nome);
        geraArquivoAleatorio(tam[i],nome);
        v = (int*)malloc(tam[i]*sizeof(int));
        if(!v){
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        lerArquivo(v,tam[i],nome);
        mergeSort(v,0,tam[i]-1,k);
        gravaArquivo(v,tam[i],nome);
        free(v);
    }
    //cria arquivos decrescentes 
    for(i=0;i<5;i++){
        j=32;
        criaNomeArquivo(tam[i],j,nome);
        geraArquivoAleatorio(tam[i],nome);
        v = (int*)malloc(tam[i]*sizeof(int));
        if(!v){
        printf("Erro ao alocar memória.\n");
        exit(1);
        }
        lerArquivo(v,tam[i],nome);
        mergeSortInverso(v,0,tam[i]-1);
        while(j<=61){
            criaNomeArquivo(tam[i],j,nome);
            gravaArquivo(v,tam[i],nome);
            j++;
        }
        free(v);
    }
 */
    
    //realizando testes com o algoritmo - arquivos desordenados
    for(i=0;i<5;i++){
        //trocas
        trocaEComparacao[0]=0.0;
        //comparações
        trocaEComparacao[1]=0.0;
        total = 0.0;
        for(j=1;j<=30;j++){
            v = (int*)malloc(tam[i]*sizeof(int));
            if(!v){
                printf("Erro ao alocar vetor.\n");
                exit(1);
            }
            criaNomeArquivo(tam[i],j,nome);
            lerArquivo(v,tam[i],nome);
            ini = clock();
            //algoritmo escolhido
            mergeSort(v,0,tam[i]-1,trocaEComparacao);                           //função a ser alterada
            total += ((double)clock() - ini) / (CLOCKS_PER_SEC/1000);
            gravaArquivo(v,tam[i],nome);
            free(v);
        }
        copiasDeRegistro1[i] = ((trocaEComparacao[0])/30.0);
        comparacoesDeChaves1[i] = ((trocaEComparacao[1])/30.0);
        tempoDeExecucao1[i] = (total/30.0);
    }
    
    //realizando testes com o algoritmo - arquivos crescentes
    for(i=0;i<5;i++){
        //trocas
        trocaEComparacao[0]=0.0;
        //comparações
        trocaEComparacao[1]=0.0;
        total = 0.0;
        for(j=1;j<=30;j++){
            v = (int*)malloc(tam[i]*sizeof(int));
            if(!v){
                printf("Erro ao alocar vetor.\n");
                exit(1);
            }
            criaNomeArquivo(tam[i],31,nome);
            lerArquivo(v,tam[i],nome);
            ini = clock();
            //algoritmo escolhido
            mergeSort(v,0,tam[i]-1,trocaEComparacao);                           //função a ser alterada
            total += ((double)clock() - ini) / (CLOCKS_PER_SEC/1000);
            gravaArquivo(v,tam[i],nome);
            free(v);
        }
        copiasDeRegistro2[i] = ((trocaEComparacao[0])/30.0);
        comparacoesDeChaves2[i] = ((trocaEComparacao[1])/30.0);
        tempoDeExecucao2[i] = (total/30.0);
    }
    
    //realizando testes com o algoritmo - arquivos decrescentes
    for(i=0;i<5;i++){
        //trocas
        trocaEComparacao[0]=0.0;
        //comparações
        trocaEComparacao[1]=0.0;
        total = 0.0;
        for(j=32;j<=61;j++){
            v = (int*)malloc(tam[i]*sizeof(int));
            if(!v){
                printf("Erro ao alocar vetor.\n");
                exit(1);
            }
            criaNomeArquivo(tam[i],j,nome);
            lerArquivo(v,tam[i],nome);
            ini = clock();
            //algoritmo escolhido
            mergeSort(v,0,tam[i]-1,trocaEComparacao);                           //função a ser alterada
            total += ((double)clock() - ini) / (CLOCKS_PER_SEC/1000);
            gravaArquivo(v,tam[i],nome);
            free(v);
        }
        copiasDeRegistro3[i] = ((trocaEComparacao[0])/30.0);
        comparacoesDeChaves3[i] = ((trocaEComparacao[1])/30.0);
        tempoDeExecucao3[i] = (total/30.0);
    }
    
    //GERA O RELATÓRIO SOLICITADO
    relatorio = fopen(dados,"w");
    
    if(!relatorio){
        printf("Erro ao abrir arquivo.\n");
    }
     
    fprintf(relatorio,"DADOS DOS ARQUIVOS DESORDENADOS:\r\n");
    fprintf(relatorio,"\r\n");
    fprintf(relatorio,"COPIAS DE REGISTRO:\r\t\r\t");
    fprintf(relatorio,"COMPARAÇÕES DE CHAVES:\r\t\r\t\r\t");
    fprintf(relatorio,"TEMPO DE EXECUÇÃO:\r\t\r\t\r\t\r\n");
    for(i=0;i<5;i++){
         fprintf(relatorio,"%.5f\r\t\r\t\r\t",copiasDeRegistro1[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",comparacoesDeChaves1[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",tempoDeExecucao1[i]);
         fprintf(relatorio,"\r\n");
    } 
    fprintf(relatorio,"\r\n");
    
    fprintf(relatorio,"DADOS DOS ARQUIVOS CRESCENTES:\r\n");
    fprintf(relatorio,"\r\n");
    fprintf(relatorio,"COPIAS DE REGISTRO:\r\t\r\t");
    fprintf(relatorio,"COMPARAÇÕES DE CHAVES:\r\t\r\t\r\t");
    fprintf(relatorio,"TEMPO DE EXECUÇÃO:\r\t\r\t\r\t\r\n");
    for(i=0;i<5;i++){
         fprintf(relatorio,"%.5f\r\t\r\t\r\t",copiasDeRegistro2[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",comparacoesDeChaves2[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",tempoDeExecucao2[i]);
         fprintf(relatorio,"\r\n");
    }
    fprintf(relatorio,"\r\n");
    
    fprintf(relatorio,"DADOS DOS ARQUIVOS DECRESCENTES:\r\n");
    fprintf(relatorio,"\r\n");
    fprintf(relatorio,"COPIAS DE REGISTRO:\r\t\r\t");
    fprintf(relatorio,"COMPARAÇÕES DE CHAVES:\r\t\r\t\r\t");
    fprintf(relatorio,"TEMPO DE EXECUÇÃO:\r\t\r\t\r\t\r\n");
    for(i=0;i<5;i++){
         fprintf(relatorio,"%.5f\r\t\r\t\r\t",copiasDeRegistro3[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",comparacoesDeChaves3[i]);
         fprintf(relatorio,"\r\t%.5f\r\t\r\t\r\t",tempoDeExecucao3[i]);
         fprintf(relatorio,"\r\n");
    }
    fprintf(relatorio,"\r\n\r\n");
    fprintf(relatorio,"OBS: CADA LINHA DE DADOS REPRESENTA TESTES REALIZADOS "
            "COM VETORES DE TAMANHO: 10000, 12500, 15000, 20000, 30000, "
            "RESPECTIVAMENTE ");
    fprintf(relatorio,"\r\n");
    fprintf(relatorio,"OBS²: CADA VALOR É OBTIDO A PARTIR DA MÉDIA SIMPLES");
    fclose(relatorio);
  
    
    printf("Olá mundo.\n");
    
}
