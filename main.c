#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"



int main()
{
    int tam = 100;
    int *V = NULL; 
    FILE *file = NULL;
    int i = 0;
    int Numero, Numerosub, n, acaofeita = 0, algexe = 0; //para o funconamento do menu
    int buscado, buscabinres; // para funcionamento da busca binaria

    do {
        printf("\n1. Carregar arquivo de dados\n2. Buscar elemento\n3. Ordenar dados\n4. Gerar relatorio (Log)\n5. Sair\n");
        scanf(" %d", &Numero);
        while(getchar() != '\n');

        switch(Numero)
        {
            case 1:
            i = 0; //para parar de somar os valores da execução anterior
            
                file = fopen("dados.txt", "r");  // abre o arquivo
                if (file == NULL) {
                    printf("Arquivo vazio\n");
                    break;
                }
                V = (int*) malloc(tam * sizeof(int));
                while (fscanf(file, "%d", &V[i]) != EOF) {
                    i++;
                    if (i >= tam) {
                        tam *= 2; // aumenta o tamanho do vetor se precisar
                        V = (int*) realloc(V, tam * sizeof(int));
                    }
                }
                fclose(file);  //fecha o arquivo
                acaofeita = 1;
                printf("%d numeros lidos\n", i);
                n = i;
                Numero = 0; //resolver o erro do menu em loop;
                break;

            case 2:
                if (acaofeita != 1) {
                    printf("Carregue o arquivo primeiro! (opcao 1)\n");
                } else {
                    printf("\n01.Linear \n02.Binária (Apenas se estiver ordenado)\n");
                    scanf(" %d", &Numerosub);
                    while(getchar() != '\n');
                    switch(Numerosub)
                    {
                        case 1:
                            //busca sequencial aqui
                            Numero = 0; //resolver o erro do menu em loop;
                            Numerosub = 0;

                            break;
                        case 2:
                            printf("qual o numero a ser buscado?  ");
                            scanf(" %d", &buscado);
                            while(getchar() != '\n');
                            buscabinres = buscabin(buscado, V, n);
                            if(buscabinres != -1)
                            {
                                printf("elemento %d encontrado na posicao: %d", buscado, buscabinres);
                            }
                            else
                            {
                                printf("elemento nao encontrado ou vetor nao ordenado");
                            }
                            Numerosub = 0; //resolver o erro do menu em loop;

                            break;
                    }
                }
            break;

            case 3:
                if (acaofeita != 1) {
                    printf("Carregue o arquivo primeiro! (opcao 1)\n");
                } else {
                    printf("\n 01.Insert.\n02.Bubble\n03.Selection\n04.Merge\n05.Quick\n06.EXTRA\n");
                    scanf(" %d", &Numerosub);
                    
                    switch(Numerosub)
                    {
                        case 1:
                            //codigo insert
                             Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 

                            break;
                        case 2:
                            // codigo bubble
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 3:
                            //codigo selection
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 4:
                            //codigomerge
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 5:
                            //codigo quick
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 6: 
                            //codigo extra
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                    }
                }
                Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                break;

            case 4:
                if (algexe != 1) {
                    printf("Carregue o arquivo primeiro! (opcao 1)\n");
                } else {
                    //LOG
                }
                Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                break;

            default: //caso digite um numero q n tem no menu
                printf("numero invalido");
                Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                             return 0;
                break;
        }
         free(V); 
    } while (Numero != 5);
}
