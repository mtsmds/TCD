#include <stdio.h>
#include <windows.h>
#include "funcoes.h"
#include <math.h>


int buscabin (int buscado, int *vet, int tam) // recebe o numero buscado, vetor e o seu tamanho
{
    if(ordenado(vet, tam) == 1)
    {
        printf("Ordenado!\n\n");
        int ver = 0;
        int ini = 0;
        int fim = (tam - 1); // sem o -1 passa do tamanho do vetor 
        int meio;

        while(ini <= fim)
        {
            meio = (fim + ini) / 2;
            if(vet[meio] == buscado)
            {
                ver++; // verifica se encontrou o elemento
                return meio;
                break;
            }
            else if(vet[meio] > buscado)
            {
                fim = meio - 1; 
            }
            else if(vet[meio] < buscado)
            {
                ini = meio + 1;
            }
        }

        if(ver == 0) // nao encontrou o elemento
        {
            return -1; //return -1 no menu
        }
    }
    else
    {
        return -1;
    }
}





    int ordenado(int *vet, int tam) //recebe vetor e tamanho
{
    int n;
    n = tam - 1; //para n passar do tamanho do vetor
    for (int i = 0; i < n; i++) { 
        if (vet[i] > vet[i+1])
            return 0;  // não ordenado
    }
    return 1;  // ordenado
}




int* bubblesort(int *vet, int n)
{

    int i, j, key;
    int *p;

    for(i = 0; i<(n-1); i++)
    {
        for(j = 0; j< (n-1); j++) // n-1 p/ n comparar com lixo fora do vetor
        {
              if(vet[j] > vet[j+1])
             {
                 key = vet[j+1]; //
                 vet[j+1] = vet[j]; // troca
                 vet[j] = key; //
             }
        }
    }

   p = (int*) malloc(n*sizeof(int)); //liberar memoria depois (free(ponteiro do resultado))
    

    for(i = 0; i<n; i++)
    {
        p[i] = vet[i]; // atribui os valos do vetor ordenado para o ponteiro
    }
   
   return p; //retorna o endereço do vetor ordenado
}



int* selectionsort(int *vet, int n)
{

    int i, j, key, min;
    int *p;

    for(i = 0; i<(n-1); i++) // n-1 p/ n comparar com lixo fora do vetor
    {
       min = i; // o elemento do vetor que nao esta´ordenado passa a ser o menor
        for(j = i +1; j<(n); j++) // i+1 para nao ordenar elementos ja ordenados
        {
              if(vet[j] < vet[min])
             {
                min = j;
             }
           
        }
          key = vet[min]; //
                 vet[min] = vet[i]; // troca
                 vet[i] = key; //
    }

   p = (int*) malloc(n*sizeof(int)); //liberar memoria depois (free(ponteiro do resultado))
    

    for(i = 0; i<n; i++)
    {
        p[i] = vet[i]; // atribui os valos do vetor ordenado para o ponteiro
    }
   
   return p;   
}


void merge (int *V, int inicio, int meio, int fim)
{
    int p1, p2, *temp, tamanho;

    p1 = inicio;
    p2 = meio + 1; 
    tamanho = fim - inicio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));

    if (temp != NULL)
    {
        //Vai combinar o odernado
        for (int i = 0; i < tamanho; i++)
        {
            if (p1 <= meio && p2 <= fim) //A condição é: Se ainda o fim está zerado vai combinar
            {
                if (V[p1] < V [p2])
                {
                    temp[i] = V[p1++];
                }
                else
                {
                temp[i] = V[p2++];
                }
            }
            else if (p1 <= meio)
            {
                temp[i] = V[p1++];
            }
            else
            {
                temp[i] = V[p2++];
            }
        }
        //Vai copiar para o vetor original
        for (int k = 0; k < tamanho; k++) 
        {
            V[inicio + k] = temp[k];
        }
    }

    free(temp); //Libera o vetor temporario
}

void MergeSort (int *V, int inicio, int fim)
{
    int meio; 

    if (inicio < fim)
    {
        meio = floor(inicio + fim)/2;
        //chama a própia função
        MergeSort (V, inicio, meio); //primeira metade
        MergeSort (V, meio + 1, fim); //segunda metade
        merge (V, inicio, meio, fim); //Chama a função merge que vai combinar 
    }
}

void InsertionSort (int *V, int N)
{
    int aux, j, i;
    for (i = 0; i < N - 1; i++)
    {
        if (V[i] > V[i+1]) //se o vetor for maior que o proximo vetor
        {
            aux = V[i+1]; // aux vai armazenar esse proximo vetor 
            V[i+1] = V[i]; //o proximo agora é o anterior (o maior entre os dois)
            V[i] = aux; //agora V tem o valor que aux armazenou
            j = i - 1; //vai armazenar as vezes do laço para comparar com os outros 
            while (j>=0)
            {
                if (aux < V[j]) //vai comparar o aux (o numero que esta trocando) com os outros de traz
                {
                    V[j+1] = V[j];
                    V [j] = aux;
                }
                else
                {
                    break; //caso o numero nao for o maior ele para
                }
                j = j - 1; // vai ser decrementada para fazer de novo 
            }
        }
    }
void insertionSort(int v[], int n) {
    int i, j, chave;
    for(i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

/* ================= MERGE SORT ================= */
void merge(int arr[], int inicio, int meio, int fim) {

    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio;

    int *esq = (int*) malloc(tamanhoEsq * sizeof(int));
    int *dir = (int*) malloc(tamanhoDir * sizeof(int));

    for (int i = 0; i < tamanhoEsq; i++)
        esq[i] = arr[inicio + i];

    for (int i = 0; i < tamanhoDir; i++)
        dir[i] = arr[meio + 1 + i];

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsq && j < tamanhoDir) {
        if (esq[i] <= dir[j])
            arr[k++] = esq[i++];
        else
            arr[k++] = dir[j++];
    }

    while (i < tamanhoEsq)
        arr[k++] = esq[i++];

    while (j < tamanhoDir)
        arr[k++] = dir[j++];

    free(esq);
    free(dir);
}

void mergeSort(int arr[], int inicio, int fim) {

    if (inicio < fim) {

        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}

/* ================= QUICK SORT ================= */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int inicio, int fim) {

    int pivo = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);

    return i + 1;
}

void quickSort(int arr[], int inicio, int fim) {

    if (inicio < fim) {

        int indicePivo = particionar(arr, inicio, fim);

        quickSort(arr, inicio, indicePivo - 1);
        quickSort(arr, indicePivo + 1, fim);
    }
}

/* ================= TIM SORT ================= */

void timMerge(int v[], int l, int m, int r) {

    int temp[100];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {

        if (v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= m)
        temp[k++] = v[i++];

    while (j <= r)
        temp[k++] = v[j++];

    for (int x = 0; x < k; x++)
        v[l + x] = temp[x];
}

void timSort(int v[], int n) {

    int meio;

    insertionSort(v, n);

    meio = (n - 1) / 2;

    timMerge(v, 0, meio, n - 1);
}

/* ================= BUBBLE SORT ================= */
void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ================= SELECTION SORT ================= */
void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIdx = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

/* ================= FUNÇÕES AUXILIARES ================= */

void imprimir(int v[], int n){

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n");
}

void salvarVetor(int v[], int n, const char* filename){

    FILE *f = fopen(filename, "w");

    if(f == NULL){
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for(int i = 0; i < n; i++)
        fprintf(f, "%d ", v[i]);

    fprintf(f, "\n");

    fclose(f);

    printf("Vetor salvo em %s\n", filename);
}

/* ================= MAIN ================= */

int main(){

    int vetor[] = {35, 3, 9, 30, 28, 21, 43, 8, 1, 2};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    int opcao;

    clock_t inicio, fim;
    double tempo;

    printf("Escolha o algoritmo de ordenacao:\n");
    printf("1 - Insertion Sort\n");
    printf("2 - Merge Sort\n");
    printf("3 - Quick Sort\n");
    printf("4 - Tim Sort\n");
    printf("5 - Bubble Sort\n");
    printf("6 - Selection Sort\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    inicio = clock();

    switch(opcao){

        case 1: insertionSort(vetor, n); break;
        case 2: mergeSort(vetor, 0, n-1); break;
        case 3: quickSort(vetor, 0, n-1); break;
        case 4: timSort(vetor, n); break;
        case 5: bubbleSort(vetor, n); break;
        case 6: selectionSort(vetor, n); break;

        default:
            printf("Opcao invalida\n");
            return 0;
    }

    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Vetor ordenado:\n");
    imprimir(vetor, n);

    printf("Tempo de execucao: %.6f segundos\n", tempo);

    char filename[50];

    printf("Digite o nome do arquivo para salvar o vetor ordenado (ex: vetor.txt): ");
    scanf("%s", filename);

    salvarVetor(vetor, n, filename);

    return 0;
}


