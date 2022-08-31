#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 50

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

fila_t* criaFila (){
    fila_t* filaPrio = malloc(sizeof(fila_t));
    filaPrio->v = malloc(MAX*sizeof(pessoa_t));
    filaPrio->n = 0;

    return filaPrio;
}

void troca(pessoa_t *a, pessoa_t *b) {
    pessoa_t t = *a;
    *a = *b;
    *b = t;
 }
 
pessoa_t* criaPessoa(){
    pessoa_t* pessoa = malloc(sizeof(pessoa_t));
    if (!pessoa)
        return NULL;

    return pessoa;
}



char* nomeAleat(){
    char* nome;
    char* listaNomes[3] = {"Naiara", "Nayara", "Roberto"};
    nome = listaNomes [rand()%3];
    return nome;
}
void iniciaPessoa(pessoa_t* pessoa){
    strcpy(pessoa->nome , nomeAleat());
    pessoa->prioridade = rand()%40;
    pessoa->idade = rand()%100;
}



void queue(fila_t* fila , pessoa_t* pessoa) {
    fila ->n++;
    fila ->v[fila->n] = *pessoa;
/*     insereHeap(fila, fila->n-1); */
}

//testar para ver se não eh melhor fazer com k > 0
void insereHeap (fila_t* fila, int n){
    while (n > 1 && fila->v[n/2].prioridade < fila->v[n].prioridade) {
        troca(&fila->v[n], &fila->v[n/2]);
        n = n/2;
    }
}

//ainda precisa ver como inserir todas as pessoas diferentes
void heapfy (fila_t* fila, int n){
    int i;
    for (i = 0; i <= n; i++)
        insereHeap(fila, i);
}


//prototipo pra implementar com fila
void sacodeHeap(fila_t* fila, int n){
    int i = 2;
    while (i<= n){
        if (i < n && fila->v[i].prioridade < fila->v[i+1].prioridade)
            i++;
        if (fila->v[i/2].prioridade >= fila->v[i].prioridade)
            break;
        troca(&fila->v[i/2], &fila->v[i]);
        i = i*2;
    }
}


void removeHeap(fila_t* fila){
    troca(&fila->v[1], &fila->v[fila->n]);
    fila->v[fila->n].prioridade = 0;
    fila->n--;
    sacodeHeap(fila, fila->n);
}

//n = fila->n(tamanho atual da fila)
/* void heapSort (fila_t* fila, int n){
    int i;
    heapfy(fila, n);
    for (i = n; 1<i; i--){
        troca(&fila->v[1], &fila->v[i]);
        sacodeHeap(fila, i);
    }
}  */

void imprimeHeap(fila_t* fila, int N){
    int i;
    for (i=1; i <= N; i++){
        printf("\n");
/*         printf ("nome: %s\n", fila->v[i].nome);
        printf("idade: %d\n", fila->v[i].idade); */
        printf ("%d prioridade: %d\n",i ,fila->v[i].prioridade);
    }
}


int main(){
    fila_t* fila = criaFila();
    pessoa_t* pessoa = criaPessoa();
    int i;
    srand(time(NULL));

    for (i=1; i < 8; i++){
        if (fila->n < MAX){
            iniciaPessoa(pessoa);
            queue(fila, pessoa);
        }
    }

    printf("---------------------------------------");
    printf("\n");
    imprimeHeap(fila, fila->n);

    printf("---------------------------------------");
    printf("\n");
    heapfy(fila, fila->n);
    imprimeHeap(fila, fila->n);

/*     printf("---------------------------------------");
    printf("\n");
    sacodeHeap(fila, fila->n);
    imprimeHeap(fila, fila->n); */


    printf("---------------------------------------");
    printf("\n");
    removeHeap(fila);
    imprimeHeap(fila, fila->n);
    free(fila);

    return 0;
}