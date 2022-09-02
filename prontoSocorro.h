#ifndef _LIBps_t_H
#define _LIBps_t_H
#include<string.h>

struct pessoa {
    char nome [100];
    int prioridade;
    int idade;
}; 
typedef struct pessoa pessoa_t;

pessoa_t* criaPessoa();


void iniciaPessoa(pessoa_t* pessoa);

char* nomeAleat();

void troca(pessoa_t *a, pessoa_t *b);


#endif