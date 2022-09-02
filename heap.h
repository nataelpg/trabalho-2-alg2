#ifndef _LIBheap_t_H
#define _LIBheap_t_H
#include "prontoSocorro.h"
#define MAX 51

/*struct fila com ponteiro para vetor, tamanho da fila, e variaveis para contar as comparacoes*/
struct fila{
    pessoa_t *v;
    int n, comp1, comp2;
};
typedef struct fila fila_t;


/*
 *Inicializa uma fila na memoria. 
*/
fila_t* criaFila ();

/*
*Colca os elementos na fila por ordem de insercao
*/
void queue(fila_t* fila , pessoa_t* pessoa);

/*
*Retira o ultimo elemento da fila 
*/
void dequeue(fila_t* fila, int n);

/*
*Inicaliza as pessoas na fila com nome idade e prioridade
*/
void inicHeap(fila_t* fila, pessoa_t* pessoa, int n);

/*
 *Insere na heap o elemento enviado como parâmetro, sendo n o número de elementos.
*/
void insereHeap (fila_t* fila, int n);

/*
 *Remove o elemento na heap.
*/
void removeHeap(fila_t* fila);

/*
 *Transforma o vetor em uma heap, recebendo o vetor e o número de elementos.
*/
void heapfy (fila_t* fila, int n);

/*
*coloca elemento na posicao correta da heap
*/
void sacodeHeap(fila_t* fila, int n);

/*
 *Ordena o vetor pelo método heapSort.
*/
void heapSort (fila_t* fila, int n);

/*
 *Imprime todos os elementos da heap.
*/
void imprimeHeap(fila_t* fila, int n);

/*
* Recebe o elemento que tera a prioridade alterada e reposiciona ele na heap
*/
void desceHeap(fila_t* fila, int k, int novo);

/* 
 *Altera a prioridade de um elemento da heap e reposiciona ele
*/
void alteraHeap(fila_t* fila, int n, int novo);

/*
 *Checa se o vetor de n elementos recebido é uma heap. 
*/
int checaHeap(fila_t* fila, int n);

#endif