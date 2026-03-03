#include <stdio.h>
#include "funcoes.h"

int buscabin (int buscado, int *vet, int tam) // recebe o numero buscado, vetor e o seu tamanho
{

    if(ordenado(vet, tam) == 0)
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
            return meio;
            
            // printf("elemento %d encontrado na posicao: %d", buscado, meio); // return meio?

            ver++; // verifica se encontrou o elemento
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
   return 1; //return -1 no menu
   }

    }

}





    int ordenado (int *vet, int tam) // recebe vetor e o seu tamanho
{
    int i = 0, cont = 0;
    
    
    while (vet[i] <= tam) //laço ate encontrar o fim do vetor
    {
        if(vet[i] > vet[i+1]) //verifica se esta ordenado
        {
           return 1; // retorna erro na ordenação
           break;
        }
    
     return 0;
      i++; // para continuar o laço
      cont++;
    }
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
   
   return p;   
}
