#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "heap.h"
#include "prontoSocorro.h"

/*
*Case 0: termina o programa
*Case 1: Inicializa a Heap;
*
*
*
*
*
*
*
*/

int main(){

    int opcao, tam, i, prioridade;
    char nome[100];
    fila_t* fila = criaFila();
    pessoa_t* pessoa = criaPessoa();

    do{
        printf("\n\t0 - Sair\n\t1 - IniciaHeap\n\t2 - InsereHeap\n\t3 - removeHeap\n\t4 - heapfy\n\t5 - HeapSort\n\t6 - checaHeap\n\t7 - AlteraHeap\n\t8 - ImprimeVetor\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            if (fila->n == 0){
                printf ("Insira o numero de pacientes na fila: ");
                scanf ("%d", &tam);
                while (tam > MAX){
                    printf ("\ntamanho maximo nao respeitado, tente outro! \n");
                    printf ("Insira o numero de pacientes na fila: ");
                    scanf ("%d", &tam);                    
                }
                inicHeap(fila, pessoa, tam);
                printf ("heap inicializada com sucesso!");
            }
            else
                printf("heap ja existe!");
                            
            break;
        case 2:
            printf ("Faça o cadastro do paciente: \n");
            printf("Nome: ");
            scanf("%s", nome);
            strcpy(pessoa->nome , nome);
            printf("\nIdade: ");
            scanf("%d", &pessoa->idade);
            printf("\nMal estar: ");
            scanf("%d", &pessoa->prioridade); 
            queue(fila, pessoa);                      
            insereHeap (fila, fila->n);
            break;
        case 3:
            if (fila->n == 0)
                printf("\nimpossivel remover fila sem pacientes!!");
            else{
                if (checaHeap(fila, fila->n)){
                    removeHeap(fila);
                    printf ("\npaciente atendido com sucesso!");
                }
                else{
                    dequeue(fila, fila->n);
                    printf("\npaciente decidiu sair da fila");
                }
            }
            break;
        case 4:
            if (fila->n == 0)
                printf("\nfila sem pacientes!!");
            else{
                heapfy(fila, fila->n);
                printf ("\na heap está feita!");
            }    
            break;
        case 5:
            if (fila->n == 0)
                printf("\nfila sem pacientes!!");
            else{
                heapSort(fila, fila->n);
                printf ("\nFila ordenada em ordem crescente!");
            }
            break;
        case 6:
            if (fila->n == 0)
                printf("fila vazia!!");
            else
                if (checaHeap(fila, fila->n))
                    printf ("\neh heap!\n");
                else
                    printf ("\nnao eh heap!\n");
            break;
        case 7:
            if (fila->n == 0)
                printf("\nfila sem pacientes!!");
            else{
                printf ("Digite qual paciente voce deseja alterar a prioridade e a sua nova prioridade: ");
                scanf("%d%d", &i, &prioridade);
                alteraHeap(fila, i, prioridade);
                printf ("\nPrioridade do paciente alterada com sucesso!");
            }
            break;
        case 8:
            printf("---------------------------------------");
            printf("\n");
            printf ("\nos pacientes na fila são: \n");
            imprimeHeap(fila, fila->n);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    free(pessoa);
    free(fila->v);
    free(fila);

    return 0;

}