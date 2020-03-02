
#ifndef ARQUIVO_H
#define ARQUIVO_H

/*gera um arquivo com uma sequência de números aleatórios*/
void geraArquivoAleatorio(int tam,char *nome);
/*lê um arquivo gerado previamente*/
void lerArquivo(int* v, int tam, char nome[]);
/*mostra os valores armazenados em um arquivo*/
void mostrarArquivo(int tam);
/*cria nome do arquivo para facilitar gerar vários arquivos*/
void criaNomeArquivo(int tam,int indice, char nomeArq[]);
/*grava arquivo ordenado sobrescrevendo o arquivo original*/
void gravaArquivo(int *v,int tam,char nome[]);

#endif /* ARQUIVO_H */

