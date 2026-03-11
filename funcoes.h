#include <stdio.h>

int buscabin (int buscado, int *vet, int tam); // algoritmo de busca binária

int ordenado (int *vet, int tam); // verifica se está ordenado

int* bubblesort(int *vet, int n); //algoritmo de ordenação bubble

int* selectionsort(int *vet, int n); //algoritmo de ordenação selection

int buscalinear(int buscado, int *v, int n);

void salvarvetor(int *v, int n); // algoritmo para salvar o vetor ordenado em um arquivo

void merge (int *V, int inicio, int meio, int fim); //merge para ordenação e junção do vetor

void MergeSort (int *V, int inicio, int fim); //algoritmo que vai "cortar" o vetor

void InsertionSort (int *V, int N); //algoritmo de ordenação inserion sort

int *quicksort(int *v, int n); 

void timMerge(int v[], int l, int m, int r);
void timSort(int v[], int n);