//InicHeap, InsereHeap, RemoveHeap, Heapfy, ChecaHeap, ImprimeHep, HeapSort 

/*
 *Inicializa a heap na memória. 
*/
void inicHeap(int * vetor);

/*
 *Insere na heap o elemento enviado como parâmetro, sendo n o número de elementos.
*/
void insereHeap(int * vetor, int n, int elemento);

/*
 *Remove o elemento na heap.
*/
void removeHeap(int * vetor);

/*
 *Transforma o vetor em uma heap, recebendo o vetor e o número de elementos.
*/
void heapfy(int * vetor, int n);

/*
 *Checa se o vetor de n elementos recebido é uma heap. 
*/
void checaHeap(int * vetor, int n);

/*
 *Imprime todos os elementos da heap.
*/
void imprimeHeap(int * vetor, int n);

/*
 *Ordena o vetor pelo método heapSort.
*/
void heapSort(int * vetor, int n);