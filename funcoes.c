#include <stdio.h>
#include <windows.h>
#include "funcoes.h"
#include <math.h>

int buscalinear(int buscado, int *v, int n)
{
    int i;
    int cont = 0;
    for(i = 0; i< (n-1); i++)
    {
        if(buscado == v[i])
        {
            return i; 
        }
    }    
    return -1; //nao encontrou o numero
    
  
}
int buscabin (int buscado, int *vet, int tam) // recebe o numero buscado, vetor e o seu tamanho
{
    if(ordenado(vet, tam) == 1)
    {
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

   p = (int*) malloc(n*sizeof(int)); 

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
        // combina os dois sub-vetores ordenados
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
}

///////////////////////

void troca(int *a, int *b) //parte do quicksort
{
    int temp = *a;  // 
    *a = *b;        //trocas
    *b = temp;      // 
}

int particao(int *v, int ini, int fim) //parte do quicksort
{
    int pivo = v[fim]; // escolhe o ultimo elemento como pivo 
    int i = ini - 1;   // define i como ultimo elemento menor que o pivo
    for (int j = ini; j < fim; j++) {
        if (v[j] <= pivo) { // se o elemento atual for <= ao pivo move para a esquerda 
            i++;
            troca(&v[i], &v[j]); // coloca o elemento menor na posicao correta 
        }
    }
    troca(&v[i + 1], &v[fim]); // coloca o pivo na posicao correta entre menores e maiores 
    return i + 1; // retorna o indice do pivo 
}

void quicksort_res(int *v, int ini, int fim) //parte do quicksort
{
    if (ini < fim) //so para quando acaba os elementos para ordenar
    {
        int pi = particao(v, ini, fim); // divide o vetor e retorna o pivo
        quicksort_res(v, ini, pi - 1); // ordena a metade esquerda
        quicksort_res(v, pi + 1, fim); // ordena a metade direita 
    }
}

int *quicksort(int *v, int n) //parte do quicksort para retornar ponteiro
{
    if (v == NULL || n <= 0) return NULL;
    quicksort_res(v, 0, n - 1);  // n-1 para nao pegar lixo do vetor
    return v;
}

void timMerge(int v[], int l, int m, int r) {
    int k = 0;
    int tamanho = r - l + 1; // tamanho do trecho a mesclar
    int *temp = (int*) malloc(tamanho * sizeof(int)); // aloca exato o necessario

    if (temp == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }

    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    while (i <= m)//
        temp[k++] = v[i++];// juntando todos os valores
    while (j <= r)//
        temp[k++] = v[j++];//
    for (int x = 0; x < k; x++)//
        v[l + x] = temp[x];//

    free(temp); // libera memoria apos uso
}

void timSort(int v[], int n) {
    int tam;
    int i;
    int bloco = 32; // tamanho escolhido como 32 pois é eficiente tanto para o insertion sort quanto para o merger sort
    // ordena blocos pequenos com InsertionSort ja pronto
    for ( i = 0; i < n; i += bloco) {
        tam = (i + bloco < n) ? bloco : n - i; // o ''?'' é um if e ":" é o else
        InsertionSort(v + i, tam); // usa InsertionSort ja existente
    }

    // junta os blocos, dobrando o tamanho a cada passagem ate cobrir o vetor 
    for (int size = bloco; size < n; size *= 2) { // size *= 2 dobra o bloco 
        for (int l = 0; l < n; l += 2 * size) {
            int m = l + size - 1;
            int r = (l + 2 * size - 1 < n - 1) ? l + 2 * size - 1 : n - 1; // evita passar do vetor
            if (m < r)
                timMerge(v, l, m, r);
        }
    }
}

void salvarvetor(int *v, int n) 
{
    FILE *f = fopen("ordenado.txt", "w"); // cria arquivo  
    if (f == NULL) //erro na criacao de arquivo
    {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\n", v[i]); // escreve o vetor no arquivo
    fclose(f); // fecha o arquivo
    printf("Vetor salvo ");
}
