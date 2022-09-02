#ifndef _LIBps_t_H
#define _LIBps_t_H
#include<string.h>

/*struct pessoa armazenando o nome a prioridade e idade de um paciente*/
struct pessoa {
    char nome [100];
    int prioridade;
    int idade;
}; 
typedef struct pessoa pessoa_t;

/*aloca espaco na memaria para a pessoa*/
pessoa_t* criaPessoa();

/*inicializa as informacoes da pessoa de forma aleatoria*/
void iniciaPessoa(pessoa_t* pessoa);

/*"cria" nome de pessoas de forma aleatoria*/
char* nomeAleat();

/* troca duas pessoas na fila */
void troca(pessoa_t *a, pessoa_t *b);


#endif