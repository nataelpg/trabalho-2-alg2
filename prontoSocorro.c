#include<stdio.h>
#include<stdlib.h>
#include "prontoSocorro.h"

pessoa_t* criaPessoa(){
    pessoa_t* pessoa = malloc(sizeof(pessoa_t));
    if (!pessoa)
        return NULL;
    
    strcpy(pessoa->nome, "");
    pessoa->prioridade = 0;
    pessoa->idade = 0;
    return pessoa;
}

void iniciaPessoa(pessoa_t* pessoa){
    char* nome = nomeAleat();

    strcpy(pessoa->nome, nome);
    pessoa->prioridade = 1 + rand()%50;
    pessoa->idade = rand()%100;

    free(nome);
}

void troca(pessoa_t *a, pessoa_t *b) {
    pessoa_t t = *a;
    *a = *b;
    *b = t;
 }

char* nomeAleat(){
    char* nome, * sobrenome, * nomeCompleto;
    nomeCompleto = malloc(sizeof(char) * 100);

    char* listaNomes[11] = {"Naiara ", "Nayara ", "Roberto ", "Pedro ", "Joao ", "Guilherme ", "Gabriel ", "Alan ", "Sofia ", "Maria ", "Julia "};
    char* listaNomes2[11] = {"Silva", "Santos", "de Almeida", "Oliveira", "Batista", "Costa", "Gomes", "Souza", "Pereira", "Ferreira", "Machado"};
    nome = listaNomes [rand()%11];
    sobrenome = listaNomes2 [rand()%11];
    
    strcat(strcpy(nomeCompleto, nome),sobrenome);
    
    return nomeCompleto;
}