#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <windows.h>


int main()
{
    LARGE_INTEGER frequency;//
    FILE *log = NULL;//
    LARGE_INTEGER inicio,fim;// funcionamento do log
    double elapsedtime;//
    double soma; // soma dos tempos de exe
    double media; //funcionamento do log
    int l; // 


    int tam = 100;
    int *V = NULL; 
    FILE *file = NULL; //arquivo de dados
    int i = 0;
    int Numero, Numerosub, n, acaofeita = 0, algexe = 0; //para o funconamento do menu
    int buscado, buscabinres; // para funcionamento da busca binaria
    int k, *ord; //funcionamento bubble e selection sort 

    do {
        printf("\n1. Carregar arquivo de dados\n2. Buscar elemento\n3. Ordenar dados\n4. Gerar relatorio (Log)\n5. Sair\n");
        scanf(" %d", &Numero);
      

        switch(Numero)
        {
            case 1:
            i = 0; //parar de somar os valores da execução anterior
            
                file = fopen("dados.txt", "r");  // abre o arquivo
                if (file == NULL) {
                    printf("Arquivo vazio\n");
                    break;
                }
                V = (int*) malloc(tam * sizeof(int)); //aloca memoria 
                while (fscanf(file, "%d", &V[i]) != EOF) { //le o arquivo
                    i++;
                    if (i >= tam) { // verifica se precisa de mais memoria
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
               
                    switch(Numerosub)
                    {
                        case 1:
                        {
                            //busca sequencial aqui
                            //
                            //

                            printf("qual o numero a ser buscado?  ");
                            scanf(" %d", &buscado);

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); // pega a frequencia do contador
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                
                                //funcao de buscalinear aqui


                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; 
                                soma += elapsedtime; // acumula o tempo 
                            }
                            media = soma / 100.0; //  media das 100 execuções
                           
                            
                            if(buscabinres != -1)
                            {
                                printf("elemento %d encontrado na posicao: %d", buscado, buscabinres);
                            }
                            else
                            {
                                printf("elemento nao encontrado");
                            }
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro\n");
                        }else
                        {
                            fprintf(log, "tempo de execução na busca sequencial: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }

                            //
                            //
                            //
                            Numero = 0; //resolver o erro do menu em loop;
                            Numerosub = 0;

                            break;
                        }
                        case 2:
                        {
                            printf("qual o numero a ser buscado?  ");
                            scanf(" %d", &buscado);

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); // pega a frequencia do contador
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                  buscabinres = buscabin(buscado, V, n);   
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; 
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; // media das 100 execuções
                        
                           
                            
                            if(buscabinres != -1)
                            {
                                printf("elemento %d encontrado na posicao: %d", buscado, buscabinres);
                            }
                            else
                            {
                                printf("elemento nao encontrado ou vetor nao ordenado");
                            }
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                            }
                            else
                            {
                            fprintf(log, "tempo de execução na busca binária: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }
                           
                        }

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
                             k = 0; //evitar erro se ordenar 2 vezes

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); // pega a frequencia do contador
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                InsertionSort(V,n);
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; 
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; // media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução insertionsort: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }
                           
                            printf("aperte 1 para ver o vetor ordenado, 2 para voltar\n");
                            scanf("%d", &k);
                         
                            if(k == 1)
                            {
                                 for(k = 0; k<n; k++)
                                 {
                                    if(k == (n-1)) //quando for o ultimo numero coloca ponto e nao virgula1
                                    {
                                        printf("%d.", V[k]);
                                        
                                    }
                                    else
                                    {
                                        printf("%d, ", V[k]);
                                    }
                                    
                                 }
                            }
                             Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 

                            break;
                        case 2:
                            // codigo bubble
                             k = 0; //evitar erro se ordenar 2 vezes

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); // pega a frequencia do contador
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                ord = bubblesort(V, n);
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; // calcula tempo da iteracao
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; // calcula a media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução bubblesort: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }
                           
                           printf("aperte 1 para ver o vetor ordenado\n");
                           scanf("%d", &k);
                            if(k == 1)
                            {
                                 for(k = 0; k<n; k++)
                                 {
                                    if(k == (n-1))
                                    {
                                        printf("%d.", ord[k]);
                                        
                                    }else{
                                        printf("%d, ", ord[k]);
                                    }
                                    
                                 }
                            }
                          
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 3:
                            //codigo selection

                            k = 0; // evitar erro se ordenar 2 vzs

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); 
                            for(l = 0; l < 100; l++) 
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                ord = selectionsort(V, n);
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; //media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a nao apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução selectionsort: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }
                           
                           printf("aperte 1 para ver o vetor ordenado\n");
                          
                           scanf("%d", &k);
                            while(getchar() != '\n');
                            if(k == 1)
                            {
                                 for(k = 0; k<n; k++)
                                 {
                                    if(k == (n-1)) //quando for o ultimo numero coloca ponto e nao virgula1
                                    {
                                        printf("%d.", ord[k]);
                                        
                                    }else{
                                        printf("%d, ", ord[k]);
                                    }
                                    
                                 }
                                }
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 4:
                            //codigomerge
                             k = 0; //evitar erro se ordenar 2 vezes

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); // pega a frequencia do contador
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem

                                MergeSort(V, 0, n - 1);

                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; 
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; //  media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução mergesort : %.10lf ms\n", media); 
                             fclose(log);
                        }
                           
                           printf("aperte 1 para ver o vetor ordenado\n");
                          // mostra a media na tela
                           scanf("%d", &k);
                            while(getchar() != '\n');  //evitar erro do menu em loop
                            if(k == 1)
                            {
                                 for(k = 0; k<n; k++)
                                 {
                                    if(k == (n-1)) //quando for o ultimo numero coloca ponto e nao virgula1
                                    {
                                        printf("%d.", V[k]);
                                        
                                    }
                                    else
                                    {
                                        printf("%d, ", V[k]);
                                    }
                                    
                                 }
                            }
                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 5:
                            //codigo quick

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); 
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                
                                 //funcao ordenação aqui
                                 // 
                                 //
                                 //
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                                soma += elapsedtime; // acumula o tempo de cada execução
                            }
                            media = soma / 100.0; // media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução quicksort: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }

                            Numero = 0; //resolver o erro do menu em loop;
                             Numerosub = 0; 
                            break;
                        case 6: 
                            //codigo extra

                            soma = 0.0; // zera a soma antes de repetir
                            QueryPerformanceFrequency(&frequency); 
                            for(l = 0; l < 100; l++) // repete 100 vezes para tirar a media
                            {
                                QueryPerformanceCounter(&inicio); // inicia contagem
                                
                                 //funcao ordenação aqui
                                 //
                                 //
                                QueryPerformanceCounter(&fim); // para contagem
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart; 
                                soma += elapsedtime; // soma os tempos
                            }
                            media = soma / 100.0; //  media das 100 execuções
                           
                            Numerosub = 0; //resolver o erro do menu em loop;
                            log = fopen("log.txt", "a"); // a n apaga o q ja tem
                            if (log == NULL) {
                            printf("Erro ao abrir log\n");
                        }else
                        {
                            fprintf(log, "tempo de execução do codigo extra: %.10lf ms\n", media); // salva a media no log
                             fclose(log);
                        }

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
            
                case 5:
                 free(V); 
                return 0;
            default: //caso digite um numero q n tem no menu
                printf("numero invalido");
                Numero = 0; //resolver o erro do menu em loop;
                Numerosub = 0; 
                             
                break;
        }
        
    } while (Numero != 5);
     free(V); 
}
