#include<stdlib.h>
#include<stdio.h>
#define N 100

void insereHeap();

void Heapfy();


int main (){
    int *vet = malloc(sizeof(int)*N); 
    insereHeap();
    Heapfy();


    free(vet);
    return 0;
}