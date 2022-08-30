#include<stdio.h>
#include<stdlib.h>

void troca(int *a, int *b) {
      int t = *a;
    *a = *b;
    *b = t;
 }
struct pessoa {
    char nome [100];
    int prioridade;
    int idade;
}; 
typedef struct pessoa pessoa_t;

struct fila{
    pessoa_t *v;
    int n, tamanho;
};
typedef struct fila fila_t;

fila_t* criaFila (int MAX){
    fila_t* filaPrio = malloc(sizeof(fila_t));
    filaPrio->v = malloc(MAX*sizeof(pessoa_t));
    filaPrio->n = 0;
    filaPrio->tamanho = MAX;

    return filaPrio;
}

void insere(fila_t* fila , pessoa_t pessoa) {
    fila ->v[fila->n] = pessoa;
    fila ->n++;
    insereHeap(fila, fila->n-1);
}

//testar para ver se não eh melhor fazer com k > 0
void insereHeap (fila_t* fila, int k){
    while (k > 1 && fila->v[PAI(k)].prioridade < fila->v[k].prioridade) {
        troca(&fila->v[k], &fila->v[PAI(k)]);
        k = k/2;
    }
}

//ainda precisa ver como inserir todas as pessoas diferentes
void heapfy (fila_t* fila, int N, pessoa_t pessoa){
    int i;
    for (i = 1; i < N; i++)
        insere(fila, pessoa);
}

void removeHeap(fila_t* fila){
    troca(&fila->v[1], &fila->v[fila->n]);
    fila->n--;
    sacodeHeap();
}

//prototipo pra implementar com fila
void sacodeHeap(){
    int aux, i = 2;
    while (i<= N){
        if (i < N && fila->v[i] < fila->v[i+1])
            i++;
        if (fila->v[i/2] >= fila->v[i])
            break;
        troca(&fila->v[i/2], &fila->v[i]);
        i = i*2;
    }
}

void imprimeHeap(){

}

void heapSort